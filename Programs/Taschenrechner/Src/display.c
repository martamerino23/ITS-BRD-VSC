/**
 * @file display.c
 * @author Franz Korf, HAW Hamburg
 * @date Mar 2016
 * @brief This modules implements a simple output module.
 *        It places two terminals in the terminal area of keypad.
 *        One terminal will be used for standard output. The other one
 *        echos pressed digit keys.
 */

#include "display.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "keypad.h"
#include "terminal.h"
#include <stdlib.h>

static Terminal stdout_term = INVALID_TERM;
static Terminal echo_term = INVALID_TERM;

void clear_stdout(void) { clearTerm(&stdout_term); }

void clear_echo_term(void) { clearTerm(&echo_term); }

void print_stdout(char *msg) { printTerm(msg, &stdout_term); }

void init_display(void) {
   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false);               // Initialisierung des LCD Boards mit Touch
   Terminal term = makeKeyPad();
   // Replace terminal by two terminals. One for standard output and
   // one to echo entered digits.
   Coordinate cor = term.bottomRight;
   cor.y = cor.y - term.font->Height - 1;
   stdout_term =
       genTerm(term.topLeft, cor, term.bgColor, term.fgColor, term.font);
   cor = term.topLeft;
   cor.y = term.bottomRight.y - term.font->Height;
   echo_term = genTerm(cor, term.bottomRight, BLUE, YELLOW, term.font);
   clear_echo_term();
   clear_stdout();
}

void print_to_echo_line(char chr) {
   char buf[2] = {'\0', '\0'};
   buf[0] = chr;
   printTerm(buf, &echo_term);
}

void set_err_mode(void) {
   clearTerm(&stdout_term);
   setTextColorTerm(RED, &stdout_term);
}

void set_normal_mode(void) {
   clearTerm(&stdout_term);
   setTextColorTerm(BLACK, &stdout_term);
}

bool is_bottom_line(void) {
   return getCurRow(&stdout_term) + 1 == getNoOfRows(&stdout_term);
}


// Helper
int count_digits(int number){
    int counter = 0;
    if(number == 0){
        return 1;
    }
    uint32_t  unum;
    if(number < 0){
        unum = (uint32_t)(-number);
    }else{
        unum = (uint32_t)number;
    }

    while(unum > 0){
        unum = unum / 10;
        counter++;
    }
    return counter;
}

void print_number(int num){

   set_normal_mode();
   char text[14] = {0};
    int i = 0;
    uint32_t  unum;
    bool negative = false;

   if(num == 0){
      text[i] = '0';
       print_stdout(text);
       return;
   }

    if(num == INT_MAX){
        strcpy(text ,"2147483647");
         print_stdout(text);
        return;
    }
    if(num == INT_MIN){
        strcpy(text,"-2147483648" );
         print_stdout(text);
        return;
    }

    if(num < 0){
        unum = (uint32_t)(-num);
        negative  = true;
    }else{
        unum = (uint32_t)num;
    }

    int digits = count_digits(num); // Number of digits of the number

    if((digits == 1) && (num != 0)){ // From 1 to 9
        text[i] = (char)unum + '0';
         print_stdout(text);
        return;
    }
    if(negative) {
        digits++; // for the minus
    }
    int exp1 = 1;
    int exp2 = 1;
    int modul = pow(10,exp1); // At the beginning always modul == 10
    int rest;
    int j = digits - 1;
    bool first = true;
    bool last = false;
    int div = pow(10,exp1);

    while(count_digits(modul) <= (digits + 1) && j >= 0){ // 10 and over
        if(negative && j ==0) {
            text[j] = '-';
            break;
        }
        if(first) {
            rest = unum % modul;
            unum = unum - rest;
            text[j] = rest + '0';
            exp1++;
            exp2++;
            j--;
            modul = pow(10,exp2);
            first = false;
        }else {
            rest = unum % modul;
            unum = unum - rest;
            text[j] = (rest / div) + '0';
            exp1++;
            j--;
            modul = pow(10,exp1);
            div = pow(10,exp2);
            exp2++;
            if(j == 0) {
                last = true;
            }

        }
    }

    print_stdout(text );
    
}

// EOF

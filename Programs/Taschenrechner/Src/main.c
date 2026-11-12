/**
 ******************************************************************************
 * @file    main.c
 * @author  Marta Muñoz
 * @brief   Taschenrechner
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/


#include "main.h"
#include "display.h"
#include "error_handling.h"
#include "stack.h"
#include "token.h"


int main(void) {

   initITSboard(); // Initialisierung des ITS Boards
   init_display(); // Initialisierung des Displays

   while(1){
      
      T_token token;
      token = next_token();
      int result = -2; // default Stack is Empty
      int number1 = 0;
      int number2 = 0;
      int stackSize2 = 0;
      
      switch(token.tok){  
         case NUMBER:  
                result =  push(token.val);
                break;
         case PLUS:
                  pop(&number1);
                  pop(&number2);
                  result = addition(number1,number2);
                  break;
         case MINUS: 
          print_to_echo_line('-');
                 if(isEmpty()){
                      print_to_echo_line('-');
                 }else if (stackSize2 >= 2){
                  pop(&number1);
                  pop(&number2);
                  result = substraction(number1, number2);
                 }
                  break;
          case MULT: 
                  pop(&number1);
                  pop(&number2);
                  result = multiplication(number1, number2);
                  break;
          case DIV:
                  pop(&number1);
                  pop(&number2);
                  result = division(number1, number2);
                  break;
          case PRT: 
                  result = printTop();
                   break;
          case PRT_ALL:
                  result = printTop3();
                  break;
          case CLEAR: 
                  result = delete();
                  set_normal_mode();
                  break;
          case DOUBLE:
                  result = duplicate();
                  break;
          case SWAP:
                  result = rOperation();
                  break;
          case UNEXPECTED :
		  result = UNKNOWN_TOKEN;
		  break;
	  case OVERFLOW:
		  result = OVERFLOWOP;
		  break;
          default: 
                  result = UNKNOWN_TOKEN;
                  break;
      }
      if(result < 0){
             errorHandling(result);   
         }
        }
}

// EOF

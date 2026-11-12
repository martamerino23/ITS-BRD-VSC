/**
  ******************************************************************************
  * @file    main.c 
  * @author  Franz Korf, HAW-Hamburg
  * @date    Januar 2018
  * @brief   Dieses Modul gehört zur Lösung der GS Klausur WS 2017-18. 
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include "general.h"

#include "lcd.h"
#include "timer.h"
#include "mytimer.h"
#include "hal.h"
#include "output.h"
#include "clock.h"
#include "myerr.h"
#include "main.h"


/* Funktionen zum Test der einzelnen Teilaufgaben ----------------------------*/

// Über die define Anweisungen werden die Testfunktionen eingebunden.

 //#define TEST_A3
 //#define TEST_A4
 //define TEST_A5


#ifdef TEST_A3
static void testA3(void) {
	initITSboard();
     initTimer();
	
	 // Warten auf Tastedruck S7
	 while (! readButton(BUTTON_PORT,PIN_SET_MODE)) { } // aktives Warten
	
	 uint32_t t = 4*1000*1000;
	 
	 // LEDs im 4 Sekunden Takt anschalten
   setOutputOfPort(LED_PORT, 0xFFFF, 0x1);
	 sleep(t);	
   setOutputOfPort(LED_PORT, 0x2, 0xFFFF);
	 sleep(t);		 
   setOutputOfPort(LED_PORT, 0x7, 0x7);
	 sleep(t);	
   setOutputOfPort(LED_PORT, 0xFFFF, 0xF);
	 sleep(t);	
   setOutputOfPort(LED_PORT, 0x0010, 0x10);

	 // Solange PIN_UP gedrueckt ist, Lauflicht im Sekundentakt.
	 while (! readButton(BUTTON_PORT,PIN_UP)) { } // aktives Warten
   setOutputOfPort(LED_PORT, 0xFFFF, 0x0000);
	 uint16_t h = 0x0001;
	 t = 1 * 1000 * 1000;
	 while (readButton(BUTTON_PORT,PIN_UP)) {
      setOutputOfPort(LED_PORT, 0xFFFF, h);
	    sleep(t);	
		  h = h << 1;
		  if (h == 0) { h = 0x0001; }
	 }
	 // Ausabe einer 3 auf den LEDs
	 setOutputOfPort(LED_PORT, 0xFFFF, timerDiffToUsec(1034 * 84, 1037 * 84));
	 while (1) { } // Test beendet
}
#endif // TEST_A3

#ifdef TEST_A4
static void waitButton7Pressed(void) {
	 // Warten auf Tastedruck S7
	 while (! readButton(BUTTON_PORT,PIN_SET_MODE)) { /* aktives Warten */ }
	 while (  readButton(BUTTON_PORT,PIN_SET_MODE)) { /* aktives Warten */ }	
}

static void testA4(void) {
	initITSboard();
	 initTimer();
	 initOutput();
	
	 waitButton7Pressed();		displayHrsMins(12, 0, true); 									// Stelle 12:00 dar
	 waitButton7Pressed();		displayHrsMins(1,  0, false);								  // Stelle 01:00 dar
	 waitButton7Pressed();		displayHrsMins(0,  0, false); 								// Stelle 00:00 dar
	 waitButton7Pressed();		displayHrsMins(3, 12, true);									// Stelle 03:12 dar
	
	 waitButton7Pressed();		setError(INTERNAL_ERR);	displayError();				// Fehlercode Ausgabe 
	 waitButton7Pressed();		initOutput(); 
	 displayHrsMins(23,  59, true);																					// Stelle 23:59 dar
	 waitButton7Pressed();		displaySec(10);																// 10 Sekunden ausgeben, Stunden Minuten bleiben erhalten
	 waitButton7Pressed();		displayHrsMins(3,  1, true);									// Stelle 03:01 dar, Sekunden bleiben erhalten
	 while (1) { } // Test beendet
}
#endif // TEST_A5

#ifdef TEST_A5

static void waitButton7Pressed(void) {
	 // Warten auf Tastedruck S7
	 while (! readButton(BUTTON_PORT,PIN_SET_MODE)) { /* aktives Warten */ }
	 while (  readButton(BUTTON_PORT,PIN_SET_MODE)) { /* aktives Warten */ }	
}

static void testA5(void) {
	initITSboard();
	 initTimer();
	 initClock();
	
	// Stellen der Uhr
	waitButton7Pressed();	addStd(3);	addMin(2);	addSec(1);	displayClock(true);	// Ausgabe der Uhrzeit 03:02:01
	waitButton7Pressed();	addStd(1);							addSec(2);	displayClock(true);	  // Ausgabe der Uhrzeit 04:02:03
	waitButton7Pressed();	addStd(20);													displayClock(true);	// Ausgabe der Uhrzeit 00:02:03
	waitButton7Pressed(); addStd(11);	addMin(1);	addSec(1);  displayClock(true);   // Ausgabe der Uhrzeit 11:03:04
	
	// Test updateClock und das Gehen der Uhr
  waitButton7Pressed(); addMin(56); addSec(45); updateClock(true); displayClock(true); // Ausgabe der Uhrzeit 11:59:49

  waitButton7Pressed();
	// Teste Gehen der Uhr
	updateClock(false);
	displayClock(true); 													
  // Ausgabe der Uhrzeit 11:59:49. 
  // Die Uhr geht im Sekundentakt weiter.
  // Bitte Wechsel der Stunde überprüfen		
	while (1) {
		 updateClock(false);
		 displayClock(true);
	}		
}
#endif // TEST_A5

/* Implemtierung der Uhr -----------------------------------------------------*/


/**
 * @brief  Die Funktion realisiert die Clock.
 *         Es wird gemäss DDC vorgegangen.
 */
void mainClock(void)
{
    initITSboard();
    initTimer();
    initClock();

    state = SET_MODUS;

    bool s7WasPressed = false;
    bool s6WasPressed = false;
    bool s6Long = false;

    while (true) {
        s7 = readButton(BUTTON_PORT, PIN_SET_MODE);
        s6 = readButton(BUTTON_PORT, PIN_UP);

        bool s7Pressed = s7 && !s7WasPressed;
        bool s6Pressed = s6 && !s6WasPressed;
       
            if(s6){
            counter++;
            }else{
                counter = 0;
                s6Long = false;
            }

            if(counter == S6_PRESSED_TIMES){
                s6Long = true;
            }

        switch (state) {
        
            case SET_MODUS:
                setOutputOfPort(LED_PORT, 0x0080, 0x0080);

                if (s7Pressed) {
                    state = SET_HOURS;
                }
                break;

            case SET_HOURS:
                if (s7Pressed) {
                    state = SET_MINS;
                }

                if(s6Long){ // Long
                    addStd(1);
                    displayClock(true);
                }

                if(s6Pressed){ //short
                     addStd(1);
                    displayClock(true);
                }
                break;

            case SET_MINS:
                 if (s7Pressed) {
                    state = SET_SECS;
                }
                if(s6Long){
                    addMin(1); 
                    displayClock(true);
                }
                if(s6Pressed){ // short
                    addMin(1);
                    displayClock(true);
                }
                break;

            case SET_SECS:
                 if (s7Pressed) {
                    state = RUNNING;
                }
                if(s6Long){
                     addSec(1);
                     displayClock(true);
                }

                if(s6Pressed){
                     addSec(1);
                     displayClock(true);
                }
                break;

            case RUNNING:
                updateClock(false);
                displayClock(true);

                if (s7Pressed) {
                    initClock();
                    updateClock(true);
                    state = SET_MODUS;
                }
                break;


            default:
                displayError();
                break;
        }

       s6WasPressed = s6;
       s7WasPressed = s7;
       sleep(ONE_MS);
    }
}

/* main Funktion,  -----------------------------------------------------------*/

/**
 * @brief  Main program
 */
int main(void) {

#ifdef TEST_A3
	 testA3();
#endif 

#ifdef TEST_A4
	 testA4();
#endif 
	
#ifdef TEST_A5
	 testA5();
#endif
   mainClock();
	 return 0;
}
// EOF

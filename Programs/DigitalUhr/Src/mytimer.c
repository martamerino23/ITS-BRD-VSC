/**
 * @file mytimer.c
 * @author IHR NAME 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es erg�nzt das Timer Modul des TI Boarda.
 */

#include "mytimer.h"

/**
 * @brief  Diese Funktion berechnet die Zeitspanne zwischen zwei
 *         Zeitstempeln. Die Funktion getTimeStamp() aus dem Modul
 *         timer.c liefert diese Zeitstempel
 * @param  firstTimeStamp ist der erste (fr�here) Zeitstempel
 * @param  secondTimeStamp ist der zweite (sp�tere) Zeitstempel
 * @retval Die Zeit (in us), die zwischen den beiden Zeitstempeln vergangen ist.
 */
uint32_t timerDiffToUsec(uint32_t firstTimeStamp, uint32_t secondTimeStamp){
    uint32_t difference = 0;

    if(secondTimeStamp < firstTimeStamp){
       difference = MAX_INT - firstTimeStamp + secondTimeStamp;
    }else{
       difference = secondTimeStamp - firstTimeStamp;
    }
    
    return difference;
}

/**
 * @brief Diese Funktion wartet die vorgegebene Zeitspanne.
 *        Sie ist durch polling der Timers realisiert.
 * @param t Die Zeit in us, die gewartet werden soll. 
 */
void sleep(const uint32_t t){
   uint32_t timeforSleep = t * TICKS_PER_US; 
   uint32_t t1 = getTimeStamp();
   uint32_t timeNow = 0;

    while(timeNow < timeforSleep){
      uint32_t t2 = getTimeStamp();
      timeNow = timerDiffToUsec(t1,t2);
    }
}


// EOF

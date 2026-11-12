/**
 * @file mytimer.h
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es erg�nzt das Timer Modul des TI Boards.
 */
 
#ifndef _MYTIMER_H
#define _MYTIMER_H

#include <stdint.h>
#include "timer.h"

#define MAX_INT 0xFFFFFFFF

/**
 * @brief  Diese Funktion berechnet die Zeitspanne zwischen zwei
 *         Zeitstempeln. Die Funktion getTimeStamp() aus dem Modul
 *         timer.c liefert diese Zeitstempel
 * @param  firstTimeStamp ist der erste (fr�here) Zeitstempel
 * @param  secondTimeStamp ist der zweite (sp�tere) Zeitstempel
 * @retval Die Zeit (in us), die zwischen den beiden Zeitstempeln vergangen ist.
 */
uint32_t timerDiffToUsec(uint32_t firstTimeStamp, uint32_t secondTimeStamp);

/**
 * @brief Diese Funktion wartet die vorgegebene Zeitspanne.
 *        Sie ist durch polling der Timers realisiert.
 * @param t Die Zeit in us, die gewartet werden soll. 
 */
void sleep(const uint32_t t);

#endif
// EOF


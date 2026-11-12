/**
  ******************************************************************************
  * @file    mytimer.h 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Interface des Moduls mytimer, das  einfache Timer Funktionen 
	*          realisiert.
  ******************************************************************************
  */

#ifndef _MYTIMER_H
#define _MYTIMER_H

#include <stdbool.h>
#include <stdint.h>
#include <stm32f4xx_hal.h>


#define MAX_INT 0xFFFFFFFF
/**
* @brief Initialisierung des Moduls mytimer und der verwendeten Module.
* @param None
* @retval None
*/
void initMyTimer(void);

 /**
* @brief Diese Funktion verz�gert die Ausf�hrung um delay Mikrosekunden.
* @param delay Mikrosekunden, um die die Funktion verzoegert.
*        delay * CONVERT2US muss kleiner als UINT32_MAX sein. Dies wird 
*        nicht ueberprueft.
* @retval None
*/
void sleep(const uint32_t delay);

 /**
* @brief Diese Funktion berechnet die Zeitspannung zwischen 2 Zeitspannen 
* @param first_time_stamp und second_time_stamp
* @retval None
*/
uint32_t timeDifference(uint32_t first_time_stamp, uint32_t second_time_stamp);


#endif
// EOF

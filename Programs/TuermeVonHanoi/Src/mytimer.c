/**
  ******************************************************************************
  * @file    mytimer.c 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Das Modul mytimer implementiert einfache Timer Funktionen.
	*          Es basiert auf dem Modul timer.
  ******************************************************************************
  */
	
#include "mytimer.h"
#include "timer.h"
#include <stdint.h>

/**
* @brief Initialisierung des Moduls mytimer und der verwendeten Module.
* @param None
* @retval None
*/
void initMyTimer(void) {
  initTimer();
}

/**
* @brief Diese Funktion verz�gert die Ausf�hrung um delay Mikrosekunden.
* @param delay Mikrosekunden, um die die Funktion verzoegert.
*        delay * TICKS_PER_US muss kleiner als UINT32_MAX sein. Dies wird 
*        nicht ueberprueft.
* @retval None
*/
void sleep(const uint32_t delay){
  uint32_t time_passed = 0;
  uint32_t time_delay = delay * TICKS_PER_US; // Number of Ticks

  uint32_t first_time_stamp = getTimeStamp();
  uint32_t second_time_stamp;
  
  while(time_passed < time_delay){
    second_time_stamp = getTimeStamp();
    time_passed = timeDifference(first_time_stamp, second_time_stamp);
  }
}

uint32_t timeDifference(uint32_t first_time_stamp, uint32_t second_time_stamp){
uint32_t difference = 0;

  if(second_time_stamp < first_time_stamp){
       difference = MAX_INT - first_time_stamp + second_time_stamp;
    }else{
       difference = second_time_stamp - first_time_stamp;
    }
    
    return difference; // Siguen siendo Ticks del reloj
}
// EOF

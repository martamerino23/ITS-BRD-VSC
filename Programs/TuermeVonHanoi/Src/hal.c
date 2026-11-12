/**
  ******************************************************************************
  * @file    hal.c 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Dieses Modul kapselt den Zugriff auf die Hardware.
  ******************************************************************************
  */

#include "hal.h"
#include "init.h"
#include "mytimer.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdint.h>


void initHal(void) {
   initITSboard();
   initLCDTouch();
   initMyTimer();
}

/**
* @brief Setzt die oberen 8 an Port E angeschlossenen LEDs (Pins 8-15)
*        gemaess dem in v uebergebenen Wert (0-255).
*/
void setzeLEDHighByte(const unsigned char v) {
  GPIO_TypeDef* port = LED_PORT; 

    uint16_t val = (uint16_t) v;
    uint16_t pinMask = (uint16_t) v;

    uint32_t setBits = pinMask & val;
    uint32_t resetBits = pinMask & ~val;

    port->BSRR = setBits | (resetBits << 16);
}

/**
* @brief Liest den Taster an Port F aus und entprellt ihn softwareseitig.
*/
bool leseTaster(const unsigned char taster) {
  if (taster > MAX_TASTER) {
     return false;
  }
  
  GPIO_TypeDef* port = BUTTON_PORT; 
  uint16_t button_mask = (uint16_t)(0x01 << taster);
  
  uint32_t wartezeit = DELTA_PRELLEN / ANZAHL_LESEVERSUCHE_PRELLEN;
  int counter = 0;

  for (int i = 0; i < ANZAHL_LESEVERSUCHE_PRELLEN; i++) {
   
    if ((port->IDR & button_mask) == 0) {
        counter++; 
    } 
    
    if (i < ANZAHL_LESEVERSUCHE_PRELLEN - 1) {
       sleep(wartezeit); 
    }
  }

  return counter == ANZAHL_LESEVERSUCHE_PRELLEN;
}




// EOF

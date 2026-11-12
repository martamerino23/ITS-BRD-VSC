/**
  ******************************************************************************
  * @file    hal.h 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Interface des Moduls hal, das  den Zugriff auf die Hardware kapselt.
  ******************************************************************************
  */

#ifndef _HAL_H
#define _HAL_H
#include <stdbool.h>
#include <stdint.h>
#include "mytimer.h"
#include "stm32f429xx.h"
#include "RTE_Device.h"
#include "init.h"


// Zuweisung der Pins der Taster, die an Port E angeschlossen sind.
#define MOV_A_B_TASTER						6
#define MOV_A_C_TASTER						5
#define MOV_B_A_TASTER						4
#define MOV_B_C_TASTER						3
#define MOV_C_A_TASTER						2
#define MOV_C_B_TASTER						1
#define RESET_TASTER			  			0

#define BUTTON_PORT             GPIOF
#define LED_PORT                GPIOE
#define MAX_LED                  256
#define DELTA_PRELLEN               20 // us
#define ANZAHL_LESEVERSUCHE_PRELLEN 5
#define MAX_TASTER                  6  


/**
* @brief Diese Funktion fuehrt die Initialisierung der Hardware durch, die von den
*        in Init_TI_Board() umgesetzten Standardeinstellungen abweicht.
* @param None
* @retval None
*/
void initHal(void);
 
/**
* @brief Diese Funktion setzt die oberen 8 an Port G angeschlossenen LEDs
*        gemaess dem in v uebergebenen Wert.
* @param v Wert, der binaer auf den LEDs ausgegeben wird.
* @retval None
*/
void setzeLEDHighByte(const unsigned char v);

/**
* @brief Diese Funktion liest den in taster uebergebenen Taster aus.
*        Der Zugriff auf den Taster wird softwareseitig entprellt.
*        Es werden maximal ANZAHL_LESEVERSUCHE_PRELLEN Leseversuche
*        durchgefuehrt. 
*        Die Prelldauer eines Tasters betraegt maximal DELTA_PRELLEN us.
* @param taster Nummer des Tasters, der ausgelesen wird.
* @retval true, wenn der Taster gedrueckt ist. Ansonsten und im Fehlerfall
*         (nicht zulaessiger Taster oder Anzahl Leseversuche ueberschritten)
*         ist der Rueckgabewert false.
*/
bool leseTaster(const unsigned char taster);
#endif
// EOF

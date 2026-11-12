/**
 * @file hal.h
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es implementiert den Zugriff auf die GPIOs.
 *        Dabei wird davon ausgegangen, dass die verwendeten Ports schon in 
 *        der durch die Funktion Init_TI_Board() gemaess ihrer Funktion als
 *        Input oder Output eingestellt wurden.
 */

#ifndef _HAL_H
#define _HAL_H

#include <stdint.h>
#include <stdbool.h>
#include "RTE_Device.h"
#include "stm32f4xx.h"
/**
 * @brief Diese Funktion setzt mehrere nebeneinander liegende Pins eines
 *        Output Ports
 *
 * @param port Das Port, dessen Pins gesetzt werden sollen.
 * @param pinMask In dieser Maske sind die Pins, die modifiziert 
 *        werden sollen, auf 1 gesetzt.
 * @param val Dieser Parameter stellt die Werte der zu modifizierenden Pins dar. 
 */
void setOutputOfPort(GPIO_TypeDef* port, uint16_t pinMask, uint16_t val);

/**
 * @brief Diese Funktion liest einen Pin ein, an den ein Druckschalter
 *        angeschlossen ist. Der Druckschalter wird beim Dr�cken auf Masse
 *        geschaltet und liefert dann eine 0.
 *
 *        �ber einen einfachen Delay Mechanismus wird eine softwaremaessige 
 *        Entprellung realisiert.
 *        
 *        Im Fehlerfall wird der entsprechende Error Code gesetzt.
 * @param port Das Port, an dem der Druckschalter angeschlossen ist.
 * @param pin Nummer des Pins, an dem der auszulesende Druckschalter angeschlossen ist.
 *        Der Wertebereich 0 bis 15 des Parameters wird �berpr�ft. 
 * @retval Die Funktion liefert true, genau dann wenn der Schalter gedrueckt ist.
 */
bool readButton(GPIO_TypeDef* port, unsigned char pin);



#endif
// EOF

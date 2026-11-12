/**
 * @file general.h
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es stellt die grundlegenden Konstanten und IO Einstellungen bereit.
 */

#ifndef _GENERAL_H
#define _GENERAL_H


// Diese Verz�gerung definiert die Zeitspanne zwischen f�r einen Schritt im Set Mode 
// 1/(5Hz) = 0,2 s = SET_DELAY us
#define SET_DELAY					(200 * 1000)

#define BUTTON_PORT        GPIOF

#define PIN_SET_MODE	    7
#define PIN_UP			6

#define LED_PORT   		   GPIOD

// LED die anzeigt, ob die Uhr im SET Mode ist
#define SET_MOD_LED				15

// 6 LEDs zur Darstellung der Sekunden
#define FIRST_LED_SECS			0
#define LED_SECS_MASK				(0x003F << FIRST_LED_SECS)

#endif
// EOF

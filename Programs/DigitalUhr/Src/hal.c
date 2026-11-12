/**
 * @file hal.c
 * @author IHR NAME 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es implementiert den Zugriff auf die GPIOs.
 */

#include "hal.h"
#include "myerr.h"
#include "mytimer.h"

#define BOUNCE_DELAY   			(5*1000)     // us
#define NO_READ_ATTEMPTS		3            // Anzahl Leseversuche f�r die Verz�gerung beim Entprellen
#define MAX_PIN_OF_PORT			15           // Gr�esste gueltige Pin Nummer
 
/**
 * @brief Diese Funktion setzt mehrere nebeneinander liegende Pins eines
 *        Output Ports
 *
 * @param port Das Port, dessen Pins gesetzt werden sollen.
 * @param pinMask In dieser Maske sind die Pins, die modifiziert 
 *        werden sollen, auf 1 gesetzt.
 * @param val Dieser Parameter stellt die Werte der zu modifizierenden Pins dar. 
 */
void setOutputOfPort(GPIO_TypeDef* port, uint16_t pinMask, uint16_t val){

    uint32_t setBits = pinMask & val;
    uint32_t resetBits = pinMask & ~val;

    port->BSRR = setBits | (resetBits << 16);
}

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
bool readButton(GPIO_TypeDef* port, unsigned char pin)
{
    if (pin > MAX_PIN_OF_PORT) {
        setError(IO_ERR);
        return false;
    }

    uint16_t mask = (uint16_t)(1U << pin);
    unsigned int pressedCount = 0;

    for (int i = 0; i < NO_READ_ATTEMPTS; i++) {
        if ((port->IDR & mask) == 0) {
            pressedCount++;
        }

        if (i < NO_READ_ATTEMPTS - 1) {
            sleep(BOUNCE_DELAY);
        }
    }

    return pressedCount == NO_READ_ATTEMPTS;

    return false;
}

// EOF

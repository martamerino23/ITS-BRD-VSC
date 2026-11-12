/**
 * @file clock.c
 * @author IHR NAME 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es implementiert die Funktionen der Uhr.
 */
#include <stdint.h>

#include "clock.h"
#include "general.h"
#include "myerr.h"
#include "output.h"
#include "timer.h"

/**
 * @brief  Diese Funktion initialisiert die Uhr
 */
void initClock(void){

    initOutput();
    hours = 0;
    minutes = 0;
    seconds = 0;
    displayClock(true);
}

/**
 * @brief  Die Funktion addiert hrs Stunden auf die aktuelle Uhrzeit.
 * @param  hrs Anzahl der Stunden, die auf die Uhrzeit addiert werden.
 * @retval None
 */
void addStd(unsigned char hrs){

 hours = (hours + hrs) % TOTAL_HRS;
}

/**
 * @brief  Die Funktion addiert mins Minuten auf die aktuelle Uhrzeit.
 * @param  mins Anzahl der Minuten, die auf die Uhrzeit addiert werden.
 * @retval None
 */
void addMin(unsigned char mins){
    uint16_t total = minutes + mins;
    minutes = total % TOTAL_MINS; // Asumiendo TOTAL_MINS es 60
    addStd(total / TOTAL_MINS);
}

/**
 * @brief  Die Funktion addiert secs Sekunden auf die aktuelle Uhrzeit.
 * @param  secs Anzahl der Sekunden, die auf die Uhrzeit addiert werden.
 * @retval None
 */
void addSec(unsigned char secs){

     uint16_t total = seconds + secs;
    seconds = total % TOTAL_SECS; 
    addMin(total / TOTAL_SECS);
}

/**
 * @brief  Diese Funktion aktualisiert die Uhrzeit  gemaess der 
 *         fortgeschrittenen Zeit. 
 *         Dazu wird die Zeitspanne, die seit dem letzten Aufruf von updateClock 
 *         vergangnen ist, auf die aktuelle Uhrzeit addiert. Die Zeitspanne 
 *         wird mit dem Timer aus dem Modul timer.c gemessen.
 * @param  restart Ist dieser Parameter true, wird die Zeitdifferenz seit dem 
 *         letzten Aufruf von updateClock nicht beachtet und somit nicht auf die 
 *         aktuelle Uhrzeit addiert.
 *         Dies ist notwendig, wenn die Uhr den SET Mode verl�sst und die im SET
 *         Mode eingestellte Zeit exakt �bernommen werden soll.
 * @retval None
 */
void updateClock(bool restart){

    uint32_t timePast = 0;
    uint32_t newUpdate = getTimeStamp();

     if(restart){
        lastUpdate = newUpdate;
        return;
        }
    
    timePast = timerDiffToUsec(lastUpdate,newUpdate) + leftover_usec; // in Mikrosekunden
    // Convertion of ticks in secs
    uint32_t full_seconds = timePast / 1000000; // (1 seg = 1.000.000 us)
    leftover_usec = timePast % 1000000;
    if(full_seconds > 0){
        addSec((unsigned char) full_seconds);
    }
    
    lastUpdate = newUpdate;
       
}

/**
 * @brief  Diese Funktion gibt die Uhrzeit auf dem Display und den LEDs aus.
 *         Die entsprechenden Ausgabefunktionen aus dem Modul output.c werden
 *         aufgerufen.
 * @brief  update Dieser Parameter erzwingt, dass die Ausgabe auf dem Display auf 
 *                jeden Fall aktualisert wird.
 * @retval none
 */

void displayClock(bool update){

    if(update){
    displayHrsMins(hours, minutes ,update);
    displaySec(seconds);
    }

}


// EOF


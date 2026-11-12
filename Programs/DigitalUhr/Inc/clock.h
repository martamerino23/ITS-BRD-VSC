/**
 * @file clock.h
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es stellt eine einfache Implementierung eines Uhr da.
 */
 
#ifndef _CLOCK_H
#define _CLOCK_H

#include <stdbool.h>
#include <mytimer.h>

#define TOTAL_HRS 24
#define TOTAL_MINS 60
#define TOTAL_SECS 60


static unsigned char hours = 0;
static unsigned char minutes = 0;
static unsigned char seconds = 0;
static uint32_t lastUpdate = 0;
static uint32_t leftover_usec = 0;

/**
 * @brief  Diese Funktion initialisiert die Uhr
 */
void initClock(void);

/**
 * @brief  Die Funktion addiert hrs Stunden auf die aktuelle Uhrzeit.
 * @param  hrs Anzahl der Stunden, die auf die Uhrzeit addiert werden.
 * @retval None
 */
void addStd(unsigned char hrs);

/**
 * @brief  Die Funktion addiert mins Minuten auf die aktuelle Uhrzeit.
 * @param  mins Anzahl der Minuten, die auf die Uhrzeit addiert werden.
 * @retval None
 */
void addMin(unsigned char mins);

/**
 * @brief  Die Funktion addiert secs Sekunden auf die aktuelle Uhrzeit.
 * @param  secs Anzahl der Sekunden, die auf die Uhrzeit addiert werden.
 * @retval None
 */
void addSec(unsigned char secs);

/**
 * @brief  Diese Funktion aktualisiert die Uhrzeit  gemaess der 
 *         fortgeschrittenen Zeit. 
 *         Dazu wir die Zeitspanne, die seit dem letzten Aufruf von updateClock 
 *         vergangnen ist, auf die aktuelle Uhrzeit addiert. Die Zeitspanne 
 *         wird mit dem Timer aus dem Modul timer.c gemessen.
 * @param  restart Ist dieser Parameter true, wird die Zeitdifferenz seit dem 
 *         letzten Aufruf von updateClock nicht beachtet und somit nicht auf die 
 *         aktuelle Uhrzeit addiert.
 *         Dies ist notwendig, wenn die Uhr den SET Mode verl�sst und die im SET
 *         Mode eingestellte Zeit exakt �bernommen werden soll.
 * @retval None
 */
void updateClock(bool restart);

/**
 * @brief  Diese Funktion gibt die Uhrzeit auf dem Display und den LEDs aus.
 *         Die entsprechenden Ausgabefunktionen aus dem Modul output.c werden
 *         aufgerufen.
 * @brief  update Dieser Parameter erzwingt, dass die Ausgabe auf dem Display auf 
 *                jeden Fall aktualisert wird.
 * @retval none
 */

void displayClock(bool update);

#endif
// EOF


/**
 * @file output.h
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es implementiert alle Ausgaben
 */

#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <stdbool.h>
#include "myerr.h"
#include <stdio.h>
#include "lcd.h"
#include "general.h"
#include "hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "init.h"

/*
 ****************************************************************************************
 *  @brief Dies Funktion initialisiert das TFT Display.
 *
 ****************************************************************************************/
void initOutput(void);

/*
 ****************************************************************************************
 *  @brief Diese Funktion gibt den aktuellen Fehlercode aus.
 *         Liegt kein Fehler vor, wird keine Ausgabe erzeugt.
 *
 ****************************************************************************************/
void displayError(void);

/*
 ****************************************************************************************
 *  @brief Diese Funktion gibt die als Parameter �bergebene Anzahl der Stunden und
 *         Minuten im Format 
 *                             HH-MM
 *         auf dem TFT Display aus. Zuvor wir der Bildschirm gel�scht.
 *
 *         Das TFT Display wird nur aktualisiert, wenn die Ausgabe sich ge�ndert hat.
 *
 *  @param hrs        Anzahl der Stunden, die ausgegeben werden sollen.
 *                    Der Wertebereich des Parameters 0 .. 23 wird �berpr�ft.
 *  @param mins       Anzahl der Minuten, die ausgegeben werden sollen.
 *                    Der Wertebereich des Parameters 0 .. 59 wird �berpr�ft.
 *  @param update     Ist dieser Parameter true, wird die Ausgabe auf dem Bildschirm 
 *                    auf jeden Fall aktualisiert.
 *
 ****************************************************************************************/
void displayHrsMins(unsigned char hrs, unsigned char mins, bool update);

/*
 ****************************************************************************************
 *  @brief Diese Funktion gibt die als Parameter �bergebene Anzahl der Sekunden 
 *         auf den entsprechenden LEDs bin�r aus. 
 *  @param secs       Anzahl der Sekunden, die ausgegeben werden sollen.
 *                    Der Wertebereich des Parameters 0 .. 59 wird �berpr�ft.
 *
 ****************************************************************************************/
 void displaySec(unsigned char secs);

#endif /* _OUTPUT_H */

// EOF

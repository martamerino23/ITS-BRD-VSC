/**
  ******************************************************************************
  * @file    spielfeld.h 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Interface des Moduls spielfeld, das die drei Tuerme	auf dem 
	*          TFT Display darstellt.
  ******************************************************************************
  */

#ifndef _SPIELFELD_H
#define _SPIELFELD_H
#include "general.h"

#define BASE_LINE 300
#define BASE_LENGTH 43

static char base[BASE_LENGTH] = {'0'};

void initSpielfeld(void);

void printTurm(const enum TurmNummer turm, TurmHoehe hoehe, SteinGroesse stein);

#endif
// EOF

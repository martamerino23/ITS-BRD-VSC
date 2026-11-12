/**
  ******************************************************************************
  * @file    logik.h 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Interface des Moduls logik.
  ******************************************************************************
  */

#ifndef _LOGIK_H
#define _LOGIK_H
#include <stdbool.h>
#include "hal.h"
#include "general.h"


static int counterZ;
static int turmA[ANZAHL_STEINE] = {6,5,4,3,2,1};
static int turmB[ANZAHL_STEINE] = {0,0,0,0,0,0};
static int turmC[ANZAHL_STEINE] = {0,0,0,0,0,0};

void initSpiel(void);

bool bewegeStein(const unsigned char richtung);

int getObererstePos(enum TurmNummer turm);

int getOberersteStein(enum TurmNummer turm,int pos);

int setStein(enum TurmNummer turm, int stein);

int getHoehe(int stein);

#endif
//EOF

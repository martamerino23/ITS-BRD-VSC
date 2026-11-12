/**
  ******************************************************************************
  * @file    logik.c 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Das Modul logik implementiert das Modell / die Logik des Spiels.
  ******************************************************************************
  */
#include "logik.h"
#include "general.h"
#include "spielfeld.h"
#include <stdbool.h>



/**
* @brief Diese Funktion initialisiert das Spiel. Auf Turm A werden alle Steine
*        gestapelt. Auf die beiden anderen Tuerme werden Steine der Groesse 0
*        gelegt.
*        Das TFT Display wird entsprechend belegt.
* @param None
* @retval None
*/
void initSpiel(void) {
 for (int i = 0; i < ANZAHL_STEINE; i++) {
        turmA[i] = ANZAHL_STEINE - i;
        turmB[i] = 0;
        turmC[i] = 0;
    }

  counterZ = 0;
  setzeLEDHighByte(0);
  initSpielfeld();
}

/**
* @brief Diese Funktion bewegt einen Stein gemaess dem Parameter richtung
*        von einem Quellturm zu einem Zielturm.
*        Das TFT Display wird entsprechend angesteuert.
*        Bei einem nicht zulaessigen Eingabeparameter oder bei einem nicht 
*        zulaessigen Spielzug (z.B. der Stein kann aufgrund seiner Groesse nicht
*        auf den Zielturm gelegt werden) wird keine Funktion ausgefuehrt.
* @param richtung Definition von Quell- und Zielturm gemaess der Definition aus 
*        general.h (MOV_A_B ...)
* @retval true genau dann wenn ein Stein bewegt wurde
*/

bool bewegeStein(const unsigned char richtung) {

  if(richtung == DEFAULT){
      return false;
  }

int pos = 0;
int posZiel = 0;
int stein = 0;


enum TurmNummer quellTurm = QUELL_TURM(richtung);
enum TurmNummer zielTurm = ZIEL_TURM(richtung);

pos = getObererstePos(quellTurm);
if(pos< 0){
  return false;
}
stein = getOberersteStein(quellTurm,pos);

 
posZiel = getObererstePos(zielTurm);
 
  if(posZiel >= 0){
    int obersterStein = getOberersteStein(zielTurm, posZiel);
    if(stein > obersterStein){
        return false;
    }
  }
 
  if(!setStein(zielTurm,stein)){
    return false;
  }

   // Stein im Quellturm entfernen
    if(quellTurm == TurmA) {
        turmA[pos] = 0;
    }
    else if(quellTurm == TurmB) {
        turmB[pos] = 0;
    }
    else if(quellTurm == TurmC) {
        turmC[pos] = 0;
    }


printTurm(quellTurm, pos, KEIN_STEIN); // delete 
printTurm(zielTurm, posZiel + 1, stein); // set new stein
counterZ++; 

setzeLEDHighByte(0);
setzeLEDHighByte(counterZ);
  return true;
}

// Return position, nicht groeße
int getObererstePos(enum TurmNummer turm){

 
  if(turm == TurmA){
    for(int i = 0; i < ANZAHL_STEINE;i++){
        if(turmA[i]==0){
          return i - 1;
        }
    }
  }

   if(turm == TurmB){
    for(int i = 0; i < ANZAHL_STEINE;i++){
        if(turmB[i]==0){
          return i - 1;
        }
    }
  }

   if(turm == TurmC){
    for(int i = 0; i < ANZAHL_STEINE;i++){
        if(turmC[i]==0){
          return i - 1;
        }
    }
  }
  return ANZAHL_STEINE - 1;
}

int getOberersteStein(enum TurmNummer turm, int pos){

  if(turm == TurmA){
   return turmA[pos];
  }

   if(turm == TurmB){
    return turmB[pos];
  }

   if(turm == TurmC){
    return turmC[pos];
  }

  return 0;// false
}

int  setStein(enum TurmNummer turm, int stein){

  if(turm == TurmA){
    for(int i = 0;i< ANZAHL_STEINE;i++){
      if(turmA[ANZAHL_STEINE -1] != 0){
        return false;
      }
      if(turmA[i] == 0){
        turmA[i] = stein;
        return true;
      }
    }
  }

  if(turm == TurmB){
    for(int i = 0;i< ANZAHL_STEINE;i++){
      if(turmB[ANZAHL_STEINE -1] != 0){
        return false;
      }
        if(turmB[i] == 0){
        turmB[i] = stein;
         return true;
      }
     
    }
  }

  if(turm == TurmC){
    for(int i = 0;i< ANZAHL_STEINE;i++){
      if(turmC[ANZAHL_STEINE -1] != 0){
        return false;
      }
      if(turmC[i] == 0){
        turmC[i] = stein;
         return true;
      }
     
    }
  }
  return false;
}

// EOF

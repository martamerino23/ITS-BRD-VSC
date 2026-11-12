/**
 * @file output.c
 * @author IHR NAME 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es implementiert alle Ausgaben.
 **/
	


// Definiton des Terminalbereichs f�r die Fehlerausgabe
#include "RTE_Device.h"
#include "myerr.h"
#define TERM_FONT     2
#define TERM_POS_X   10
#define TERM_POS_Y    4
#define TERM_COLUMNS 14
#define TERM_LINES    5

#include "output.h"

/*
 ****************************************************************************************
 *  @brief Dies Funktion initialisiert das TFT Display.
 *
 ****************************************************************************************/
void initOutput(void){
   initLCDTouch();
}

/*
 ****************************************************************************************
 *  @brief Diese Funktion gibt den aktuellen Fehlercode aus.
 *         Liegt kein Fehler vor, wird keine Ausgabe erzeugt.
 *
 ****************************************************************************************/
void displayError(void){
    lcdGotoXY(TERM_POS_X,TERM_POS_Y);
    int error = (int)getError();
    switch(error){
        case INTERNAL_ERR: lcdPrintReplS("INTERNAL_ERR");
        break;
        case IO_ERR: lcdPrintReplS("IO_ERR");
        break;
        case INVALID_HRS: lcdPrintReplS("INVALID_HRS");
        break;
        case INVALID_MINS: lcdPrintReplS("INVALID_MINS");
        break;
    }
    
}

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
void displayHrsMins(unsigned char hrs, unsigned char mins, bool update){
   
    if(hrs > 23){
        setError(INVALID_HRS);
    }

    if(mins > 59){
        setError(INVALID_HRS);
    }

    if(update){
     char timeString[6] = {0};
        sprintf(timeString, "%02d:%02d", hrs, mins);
        lcdGotoXY(TERM_POS_X, TERM_POS_Y);
        lcdSetFont(TERM_FONT);
        lcdPrintReplS(timeString); // clean und print
    }  
}

/*
 ****************************************************************************************
 *  @brief Diese Funktion gibt die als Parameter �bergebene Anzahl der Sekunden 
 *         auf den entsprechenden LEDs bin�r aus. 
 *  @param secs       Anzahl der Sekunden, die ausgegeben werden sollen.
 *                    Der Wertebereich des Parameters 0 .. 59 wird �berpr�ft.
 *
 ****************************************************************************************/
 void displaySec(unsigned char secs){
      if(secs > 59 ){
        setError(IO_ERR);
        return;
      }
      // reset 
     setOutputOfPort(LED_PORT,0xFFFF , 0X0000); 

      // set
      uint16_t value = (uint16_t)secs;
      setOutputOfPort(LED_PORT,value , value); 
    }

// EOF

/**
  ******************************************************************************
  * @file    spielfeld.c 
  * @author  <IHR NAME>
  * @date    22.1.2019
  * @brief   Diese Datei gehoert zur GS Klausur WS 2018-19 Version 1 Tuerme von Hanoi
	*          Dieses Modul implementiert die Darstellung des 
	*          Spielfelds auf dem TFT Displays.
  ******************************************************************************
  */
#include "spielfeld.h"
#include "LCD_general.h"
#include "fonts.h"
#include "fontsFLASH.h"
#include "general.h"
#include "hal.h"
#include "init.h"
#include "lcd.h"
#include <stdlib.h>
#include "fonts.h"
#include "LCD_GUI.h"

// Darstellung der Steine (bei 6 Steinen)
//	Kleinster Stein       *
//          :            ***
//          :           *****
//          :          *******
//          :         *********
//  Groesster Stein  ***********


/**
* @brief Auf dem Spielfeld werden die drei Tuerme von Hanoi dargestellt. Diese Funktion druckt einen Stein
*        der Groesse stein an der Position hoehe von Turm turm aus. 
*        Der Stein wird mittig zum Turm ausgegeben.
*        Liegt ein Parameter (hoehe, stein) ausserhalb seines Wertebereiches, wird keine Ausgabe gemacht.
*        Weitere Ueberpruefungen, wie zum Beispiel ob der Stein an der Stelle platziert werden darf, 
*        werden nicht durchgefuehrt.
*	@param turm Turm, auf dem der Stein platziert werden sollen.
* @param hoehe Position in Turm, an der der Stein platziert werden soll. Bereich: 0 bis ANZAHL_STEINE-1
* @param stein Groesse des Steins, der platziert werden soll. Bereich: 0 bis ANZAHL_STEIN
*              stein == 0 : Der aktuelle dort platzierte Stein soll geloescht werden 
*              stein = 1 : Ein Stein der Breite BREITE_STEIN(stein) soll platziert werden.
* @retval none
*/
void printTurm(const enum TurmNummer turm, TurmHoehe hoehe, SteinGroesse stein) {

  if((hoehe < 0) || (hoehe > ANZAHL_STEINE -1)){
    return;
  }

  if((stein < 0) || (stein > ANZAHL_STEINE)){
    return;
  }

  //Welcher Turm?
   int center = 0;
   int start = 0;
   //int breite = (2 * stein) - 1 ;  // lcdprintS
    int breite = (Font16FLASH.Width * (2 * stein - 1));
  switch(turm){
    case TurmA: center = XTURMGUIA; // Center von A 
                             
                break;
    case TurmB: center = XTURMGUIB; // Center von B
               
                break;
    case TurmC: center = XTURMGUIC; // Center von C
               
                 break;
    default:
                 return;
  }

   start =  center - breite/2; 
  //int hoehe2 = BASE_STEIN - hoehe; // lcdPrint
  int hoehe2 = BASE_STEINGUI - (hoehe + 1) * Font16FLASH.Height; //GUI_disStr
  Coordinate coordinate;
  coordinate.x = start;
  coordinate.y = hoehe2;
  //lcdGotoXY(start, hoehe2); // Position des Steins -1 wegen Base: pixel 19*19

  if(stein == 0){                     
   // lcdPrintS("          ");
    int breiteLoeschen = Font16FLASH.Width * 11;
   coordinate.x = center - breiteLoeschen / 2;
     GUI_disStr(coordinate, "          ", &Font16FLASH, WHITE, WHITE);
     return;
  }
          switch(stein){
            case 1:     
                        GUI_disStr(coordinate,"*", &Font16FLASH,WHITE, RED);                  
                        //lcdPrintS("*");
                      
                    break;
            case 2:                                                                            
                        //lcdPrintS("***");
                        GUI_disStr(coordinate,"***", &Font16FLASH,FONT_BACKGROUND, RED);
                    break;
            case 3: 
                         GUI_disStr(coordinate,"*****", &Font16FLASH,FONT_BACKGROUND, RED); 
                         //lcdPrintS("*****");         
                    break;
            case 4:       
                        GUI_disStr(coordinate,"*******", &Font16FLASH,FONT_BACKGROUND, RED);                            
                        //lcdPrintS("*******");                                     
                    break;
            case 5:         
                          GUI_disStr(coordinate,"*********", &Font16FLASH,FONT_BACKGROUND, RED);        
                         //lcdPrintS("*********");                     
                    break;
            case 6:         
                        GUI_disStr(coordinate,"***********", &Font16FLASH,FONT_BACKGROUND, RED);                    
                        //lcdPrintS("***********");          
                      break;
          }
}

/**
* @brief Diese Funktion initialisiert das TFT Display und das Spielfeld.
*        Das Spielfeld ist ein Window mit dem Font FONT6.
*        Der Curser wird ausgeschaltet.
*        Die Tuerme stehen auf einer Grundlinie aus = Zeichen.
* @param none
* @retval none
*/
void initSpielfeld(void){

  //lcdSetFont(FONT6); // Font setzen

  //Coodinaten 
  Coordinate coordinateBase ={0,BASE_LINE};
  for(int i = 0; i < BASE_LENGTH;i++){
     base[i] = '=';
  }
  //lcdPrintS("===========================================");
  base[BASE_LENGTH] = '\0'; // end of string
  GUI_disStr(coordinateBase,base ,&Font16FLASH,WHITE,MAGENTA);
  
  int sternenStein = ANZAHL_STEINE;
  for(int i = 0; i < ANZAHL_STEINE; i++){ 
    printTurm(TurmA,i ,sternenStein);
    sternenStein--;
  }
}
// EOF

/**
 ******************************************************************************
 * @file    operations.h
 * @author  Marta Muñoz
 * @brief   Taschenrechner
 ******************************************************************************
 */

 #ifndef OPERATIONS_H
 #define OPERATIONS_H

/* Includes------------------------------*/
#include "error_handling.h"
#include "stack.h"
#include "display.h"
#include "lcd.h"

/*Funktionen------------------------------*/

int addition(int number1, int number2);

int substraction(int number1, int number2);

int multiplication(int number1, int number2);

int division(int number1, int number2);

int duplicate();

int rOperation();

int delete();

int printTop3();

int printTop();


 #endif
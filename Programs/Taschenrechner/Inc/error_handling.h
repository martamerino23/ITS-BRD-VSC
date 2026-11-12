
/**
 ******************************************************************************
 * @file    error_handling.h
 * @author  Marta Muñoz
 * @brief   Taschenrechner
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/


#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "display.h"

#define OK 0
#define FULL_STACK -1
#define EMPTY_STACK -2
#define NOT_ENOUGH_ITEMS -3
#define UNKNOWN_TOKEN -4
#define DIVISION_0 -5
#define OVERFLOWOP -6
#define UNDERFLOW -7
#define PEEK_ERROR -8


void errorHandling(int error);

#endif
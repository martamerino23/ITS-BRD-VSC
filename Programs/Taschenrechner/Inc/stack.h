/**
 ******************************************************************************
 * @file    stack.h
 * @author  Marta Muñoz
 * @brief   Taschenrechner
 ******************************************************************************
 */

 #ifndef STACK_H
 #define STACK_H

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "error_handling.h"

/* Defines ------------------------------------------------------------------*/
#define MAX_SIZE 100

/* Variablen ----------------------------------------------------------------*/
static int stack[MAX_SIZE] = {0};

static int stackSize = 0;


/*Funktionen -----------------------------------------------------------------*/
bool isEmpty();

bool isFull();

int push(int number);

int pop(int* value);

int peek(int* value, int index);

int getStackSize(int* value);

int swap();

int clearStack();

#endif
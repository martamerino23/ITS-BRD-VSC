/**
 ******************************************************************************
 * @file    stack.c
 * @author  Marta Muñoz
 * @brief   Taschenrechner
 ******************************************************************************
 */

/* Includes -----------------------------------------------------------------*/



#include "stack.h"
#include "error_handling.h"

/*Funktionen -----------------------------------------------------------------*/

bool isEmpty(){
    if(stackSize == 0){
        return true;
    }else{
        return false;
    }   
}

bool isFull(){
    if(stackSize == MAX_SIZE){
        return true;       
    }else{
        return false;
    }
}   

int push(int number){
    if(isFull()){
        return FULL_STACK;
    }
    stack[stackSize] = number;
    stackSize++;
    return OK;
}
      
int pop(int* value){
    if(isEmpty()){
        return EMPTY_STACK;
    }
    *value = stack[stackSize - 1];
    stackSize--; 
   return OK;
}


int peek(int* value, int index){
    if(isEmpty()){
        return EMPTY_STACK;
    }

    if(index < stackSize){
        *value = stack[index];
    }  
    
    return OK;
}

int swap(){
      if(isEmpty()){
        return EMPTY_STACK;
      }
      if(stackSize >= 2){
        int number1;
        int number2;

        pop(&number1);
        pop(&number2);

        push(number1);
        push(number2); 
      }
      
    return OK;
}

int clearStack(){
   stackSize = 0;
   return OK;
}

int getStackSize(int* value){
    *value = stackSize;
    return OK;
}





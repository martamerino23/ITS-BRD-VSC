
/**
 ******************************************************************************
 * @file    error_handling.c
 * @author  Marta Muñoz
 * @brief   Taschenrechner
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/



#include "error_handling.h"
#include "display.h"

void errorHandling(int error){
    switch(error){
        case FULL_STACK:
        set_err_mode();
          print_stdout("The stack is full.\n");
        break;
        case EMPTY_STACK:
         set_err_mode();
          print_stdout("The stack is empty.\n");
        break;
        case UNKNOWN_TOKEN:
         set_err_mode();
         print_stdout("Unknown token.\n");
         break;
         case OVERFLOWOP:
         set_err_mode();
         print_stdout("Stack overflow.\n");
         break;
          case UNDERFLOW:
         set_err_mode();
         print_stdout("Stack underflow.\n");
         break;
         case PEEK_ERROR:
         set_err_mode();
         print_stdout("Peek error.\n");
         case DIVISION_0:
         set_err_mode();
         print_stdout("Division durch 0!\n");
         break;
         case NOT_ENOUGH_ITEMS:
         set_err_mode();
         print_stdout("Not enough items!!\n");
         break;
    }
}
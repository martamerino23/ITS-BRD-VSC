


#include "operations.h"
#include "display.h"
#include "error_handling.h"
#include "stack.h"
#include <limits.h>

int addition(int number1, int number2){
   
    int result = 0;
    
    if(number1 > 0 && number2 > 0){
    if(number1 > (INT_MAX - number2)){
        return OVERFLOWOP;
        }
    }

    if(number1 < 0 && number2 < 0){
        if(number1 < INT_MIN - number2){
            return UNDERFLOW;   
        }  
    }

    result = number1 + number2;
    push(result);
    return OK;
}

int substraction(int number1, int number2){

    int result = 0;
   
      
   if(number1 >= 0 && number2 < 0){
        if(number1 > INT_MAX + number2){
        return OVERFLOWOP;
        }    
   }

   if(number1 < 0 && number2 > 0){
        if(number1 < INT_MIN + number2){
        return UNDERFLOW;
        }    
   }

    result = number1 - number2;
    push(result);
    return OK;
}

int multiplication(int number1, int number2){

   
    int result = 0;


    if(number1 == 0 || number2 == 0){
        push(result);
        return OK;
    }
    
    if(number1 > 0 && number2 > 0){
        if(number1 > INT_MAX / number2){
            return OVERFLOWOP;
        }
    }

    if(number1 < 0 && number2 < 0){
        if(number1 < INT_MAX / number2){
            return OVERFLOWOP;
        }   
    }

    if(number1 < 0 && number2 > 0){
        if(number1 < INT_MIN / number2 ){
            return UNDERFLOW;
        }   
    }
  
    if(number1 > 0 && number2 < 0){
        if(number2 != -1 && (number1 > INT_MIN / number2)){
            return UNDERFLOW;
        } 
    }

    result = number1 * number2;
    push(result);
    return OK;
}
    

int division(int number1, int number2){
    if(number2 == 0){
        return DIVISION_0;
    }

    if(number1 == INT_MIN && number2 == -1){
        return OVERFLOWOP;
    }

   int result = 0;
   result = number1 / number2;
   push(result);
   return OK;
}

int duplicate(){
    int number;
    int size = 0;
    int result = 0; 
    result = getStackSize(&size);

    if(result ==OK){
        if(size < 1){
            return NOT_ENOUGH_ITEMS;
        }
    peek(&number, size - 1);
    push(number);
    }

    return OK;
}

int rOperation(){
    int result;
    result = swap();
    return result;
}

int delete(){
    int result;
    result = clearStack();
    return result;
}

int printTop3(){

     if(isEmpty()){
        return EMPTY_STACK;
    }

     int size = 0;
    getStackSize(&size);
    if(size < 3){
        return NOT_ENOUGH_ITEMS;
    }

    int top = 0;
    int result = 0; 
    for(int i = 0; i < 3; i++){
        result = peek(&top,size - 1 - i);
        if(result == OK){
                 print_number(top); 
        }
       
    }    
    return OK;
}

int printTop(){

    if(isEmpty()){
        return EMPTY_STACK;
    }
    int top = 0;
    int result = 0; 
    int size = 0;

    getStackSize(&size);
    result = peek(&top,size - 1);
    if(result == 0){
        print_number(top);
    }else{
        return PEEK_ERROR;
    }
   
    return OK;
}


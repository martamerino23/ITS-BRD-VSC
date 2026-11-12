#ifndef _MAIN_H
#define _MAIN_H

#include <stdint.h>
#include <stdbool.h>
#include "general.h"
#include "timer.h"
#include "mytimer.h"
#include "hal.h"
#include "output.h"
#include "clock.h"
#include "myerr.h"

#define ONE_MS 10000
#define S6_PRESSED_TIMES 10

typedef enum{
    SET_MODUS = 1,
    SET_HOURS = 2,
    SET_MINS = 3,
    SET_SECS = 4,
    RUNNING = 5
}ClockState;

ClockState state = SET_MODUS;
static bool s7 = false; 
static bool s6 = false;
static int counter;

#endif
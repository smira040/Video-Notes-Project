//done

#include <Arduino.h>
#include "pins.h"
#include "globals.h"

#ifndef _RGB_TICK_
#define _RGB_TICK_

enum RGBStates{
    RGB_IDLE,
    RGB_RED,
    RGB_YELLOW,
    RGB_GREEN,
};
int RGBTick(int state){
    switch (state){ //transitions
        case RGB_IDLE:
        static int i = -1;
        if (i < 0){ //skips the first tick to allow batteryPercentage to be read first
            state = (batteryPercentage >= 75) ? RGB_GREEN : 
            (batteryPercentage >= 35) ? RGB_YELLOW : RGB_RED;
            i =0;
        }
        break;

        case RGB_RED:
            state = (batteryPercentage >= 75) ? RGB_GREEN : 
            (batteryPercentage >= 35) ? RGB_YELLOW : RGB_RED;
        break;

        case RGB_YELLOW:
            state = (batteryPercentage >= 75) ? RGB_GREEN : 
            (batteryPercentage >= 35) ? RGB_YELLOW : RGB_RED;
        break;

        case RGB_GREEN:
            state = (batteryPercentage >= 75) ? RGB_GREEN : 
            (batteryPercentage >= 35) ? RGB_YELLOW : RGB_RED;
        break;

        default: break;
    }
    switch (state){ //actions
        case RGB_IDLE: 
            analogWrite(RGB_PIN_R, 0);
            analogWrite(RGB_PIN_G, 0);
        break;

        case RGB_RED:
            analogWrite(RGB_PIN_R, 255);
            analogWrite(RGB_PIN_G, 0);
        break;

        case RGB_YELLOW:
            analogWrite(RGB_PIN_R, 255);
            analogWrite(RGB_PIN_G, 65);
        break;

        case RGB_GREEN:
            analogWrite(RGB_PIN_R, 0);
            analogWrite(RGB_PIN_G, 255);
        break;

        default: break;
    }
    return state;
}

#endif
#include <Arduino.h>
#include "pins.h"
#include "globals.h"

#ifndef _JOYSTICK_TICK_
#define _JOYSTICK_TICK_

enum JoyStates{joy_idle};
int JoyTick(int state){
    switch (state){
        case joy_idle:{
            static int cx = -1, cy = -1;

            if (cx < 0) {                 // capture center once
            cx = analogRead(HORIZONTAL_PIN);
            cy = analogRead(VERTICAL_PIN);
            }


            int rawX = analogRead(HORIZONTAL_PIN) - cx;
            int rawY = analogRead(VERTICAL_PIN) - cy;

            // Serial.print("Raw X: "); Serial.println(rawX);
            // Serial.print("Raw Y: "); Serial.println(rawY);
            
            if (abs(rawX) < 20) rawX = 0;
            if (abs(rawY) < 20) rawY = 0;


            // scale to -100..100 (tune 1800 if needed)
            xVal = constrain((rawX * 100) / 1800, -100, 100);
            yVal = constrain((rawY * 100) / 1800, -100, 100);
            
            Serial.print("X: "); Serial.println(xVal);
            Serial.print("Y: "); Serial.println(yVal);
            break;
        }

        default: break;
    }
    return state;
}

#endif
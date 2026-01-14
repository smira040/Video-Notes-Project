//DONE


#include <Arduino.h>
#include "pins.h"
#include "globals.h"

#ifndef _BATTERY_TICK_
#define _BATTERY_TICK_

#define BAT_ADC 36

#define MAX_BAT 4.2
#define MIN_BAT 3.1

//R1 is connected to Vin
//R2 is connected to GND
//V_ADC  = V_BAT * (R2)/(R1+R2)
#define R1 100000.0 //100k ohm
#define R2 100000.0 //100k ohm

#define VOLTAGE_DIVIDER_FACTOR (R2/(R1+R2)) //0.5 divided the voltage in half

/* on the ESP analogRead() returns 0-4095  by default.

    Vadc = (raw/4095) * Vref    | Vref = 3.3V for ESP32
    So to get the battery voltage from the ADC reading:
    Vbat = Vadc / VOLTAGE_DIVIDER_FACTOR
    Vbat = ((raw/4095) * Vref) / VOLTAGE_DIVIDER_FACTOR
    Vbat = (raw * Vref) / (4095 * VOLTAGE_DIVIDER_FACTOR)

    To convert voltage to percentage:
    percentage = ((Vbat - MIN_BAT) / (MAX_BAT - MIN_BAT)) * 100
*/

//goal: read battery voltage from ADC pin and convert to percentage



enum BatteryStates{BATTERY_IDLE};
int BatteryTick(int state){
    switch (state){
        case BATTERY_IDLE: {
            int raw = analogRead(BAT_ADC);

            uint32_t mv = analogReadMilliVolts(BAT_ADC);
            float Vadc = mv / 1000.0f;

            float Vbat = Vadc / VOLTAGE_DIVIDER_FACTOR;

            float pct_f = ((Vbat - MIN_BAT) / (MAX_BAT - MIN_BAT)) * 100.0f;
            if (pct_f < 0.0f) pct_f = 0.0f;
            if (pct_f > 100.0f) pct_f = 100.0f;

            batteryPercentage = (unsigned int)(pct_f + 0.5f);

            Serial.print("Battery Voltage: ");
            Serial.println(Vbat, 3);

            Serial.print("Battery Percentage: ");
            Serial.println(batteryPercentage);
        }
        break;


        default: break;
    }
    return state;
}



#endif
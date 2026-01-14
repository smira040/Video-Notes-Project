#ifndef TASKS_H
#define TASKS_H
#include <Arduino.h>
#include "PINS.h"
#include "CntrlPeriods.h"
#include "Ticks/JoyTick.h"
#include "Ticks/RGBTick.h"
#include "Ticks/batteryTick.h"

//task template
typedef struct _task {
    int state;
    unsigned long period;      // in milliseconds
    unsigned long timeUnit;  
    int (*TickFct)(int);
} task;

#define NUM_TASKS 3
task tasks[NUM_TASKS];

void setupTasks() {
    tasks[0].state = joy_idle;
    tasks[0].period = joyPeriod;
    tasks[0].timeUnit = millis();
    tasks[0].TickFct = &JoyTick;

    tasks[1].state = BATTERY_IDLE;
    tasks[1].period = batteryPeriod;
    tasks[1].timeUnit = millis();
    tasks[1].TickFct = &BatteryTick;

    tasks[2].state = RGB_IDLE;
    tasks[2].period = RGBPeriod;
    tasks[2].timeUnit = millis();
    tasks[2].TickFct = &RGBTick;
}

//function to run all tasks based on their timing
void runTasks() {
    unsigned long now = millis(); //get the current time in milliseconds since the program started
    //loop through all tasks in the array
    for (int i = 0; i < NUM_TASKS; i++) {
        //check if enough time has passed to run this task again
        if ((now - tasks[i].timeUnit) >= tasks[i].period) {
            //call the task's state machine function and update its state
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            //update the last run time to the current time
            tasks[i].timeUnit = now;
        }
    }
}

#endif
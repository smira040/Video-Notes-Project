//this will be the menu on the TFT screen to select which video to play
//must read joystick input to navigate menu
//must read SD card to get list of videos
//must display menu on TFT screen
//must play selected video with audio through I2S DAC

//this will change the audioFile and videoIndex globals in globals.h

#ifndef _MENU_H_
#define _MENU_H_

#include "globals.h"

enum MenuStates{MENU_IDLE};
int MenuTick(int state){
    switch(state){
        case MENU_IDLE:{  //transitions

            //fill later
            break;
        }
        default: break;
    }
    switch (state){ //actions
        case MENU_IDLE: {
            //fill later
            break;
        }
    }
    return state;
}

#endif
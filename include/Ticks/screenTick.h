#ifndef _SCREEN_H_
#define _SCREEN_H_  

#include "globals.h"
#include "helpers.h"

/*goal: psync a sequence of images and audio to play a video on the 
TFT screen with audio output through the I2S DAC
  Steps:
    1. Initialize the TFT screen
    2. Initialize the SD card
    3. Load a sequence of images and audio files from the SD card
    4. Display the images on the TFT screen in sync with the audio playback
*/

enum ScreenStates{SCREEN_IDLE};
int ScreenTick(int state){

    switch (state){ //actions
        case SCREEN_IDLE: {
            playVideo(videoIndex);
            break;
        }
    }
    return state;
}

#endif
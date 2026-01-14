#include "globals.h"    
#include "helpers.h"
#ifndef _AUDIO_H_
#define _AUDIO_H_

/*goal: play audio files from the SD card using the I2S DAC (MAX98357)
  Steps:
    1. Initialization happens in main.cpp
    2. Read audio files from the SD card
    3. Play audio files through the I2S DAC
*/

enum AudioStates{AUDIO_IDLE};
int AudioTick(int state){
    switch(state){
        case AUDIO_IDLE:{  //action
            playAudio(audioFile);           
            break;
        }
    default: break;
    }
    return state;
}

#endif

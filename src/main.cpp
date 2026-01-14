//testing AMP

#include <Arduino.h>
#include "pins.h"
#include <DFRobot_MAX98357A.h>

String musicList[100]; 

void setup() {
  Serial.begin(115200);
  DFRobot_MAX98357A myAudio;
  
  while(!myAudio.initI2S(I2S_BCLK, I2S_LRC, I2S_DOUT)/*initiate I2S */){
    Serial.println("I2S Init Failed! Retrying...");
    delay(3000);
    return;
  }
  while(!myAudio.initSDCard(SD_CS)/*initiate SD card*/){
    Serial.println("SD Card Init Failed! Retrying...");
    delay(3000);
    return;
  }
  myAudio.scanSDMusic(musicList);
}

void loop(){

}
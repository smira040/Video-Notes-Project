#include "pins.h"
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <DFRobot_MAX98357A.h>

#ifndef GLOBALS_H
#define GLOBALS_H

const int MAX_VIDEOS = 4; //assume max 4 videos on SD card, subject to change
const int MAX_IMAGES = 20; //assume max 20 images per video, subject to change
const int MAX_PATH   = 96; //no clue what this means

struct Video{
    char folder[MAX_PATH];
    char audioPath[MAX_PATH];
    char imagePaths[MAX_IMAGES][MAX_PATH];
    int numImages;
}; Video videos[MAX_VIDEOS];

char currAudioIndex = 0;
unsigned char currVideoIndex = 0;

int totalVideos = 0;


//joystick globals
unsigned char joy_press;
int xVal, yVal = 0;

//battery globals
unsigned int batteryPercentage = 0;

//cursor globals
int cursorX = 0;
int cursorY = 0;

//Adafruit_ST7735 myScreen; //initialized in main
//DFRobot_MAX98357A myAudio; //initialized in main
#endif
#include <Arduino.h>
#include "../include/pins.h"
#include "../include/TASKS.h"

void setup() {
  Serial.begin(115200);
  pinMode(SELECT_PIN, INPUT_PULLUP); //joystick select button
  pinMode(RGB_PIN_R, OUTPUT); //RGB LED Red
  pinMode(RGB_PIN_G, OUTPUT); //RGB LED Green

  analogReadResolution(12);          // 0..4095
  analogSetPinAttenuation(HORIZONTAL_PIN, ADC_11db);
  analogSetPinAttenuation(VERTICAL_PIN,   ADC_11db);
  analogSetPinAttenuation(BAT_ADC, ADC_11db); // allows ~0-3.3V range

  //myScreen = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
  //myScreen.setRotation(0); //portrait mode
  //myScreen.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  //myScreen.fillScreen(ST77XX_BLACK);

  //myAudio = DFRobot_MAX98357A();



  setupTasks();
}

void loop() {
  runTasks(); //its given in the name
  delay(10);
}


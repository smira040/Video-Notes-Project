//Screen Pins
#define TFT_CS  13  //the cs pin must be shared between TFT and SD card will communicate on the same SPI bus along with the MAX98357
#define TFT_RST 17 //TX2
#define TFT_DC  16 //RX2

#define SPI_SCK  18
#define SPI_MOSI 23
#define SPI_MISO 19

#define SD_CS 5

// SPI SCK  (clock)
// TFT CLK     -> ESP32 GPIO18
// SD  SD_SCK  -> ESP32 GPIO18

// SPI MOSI (data from ESP32 to devices)
// TFT SDA     -> ESP32 GPIO23
// SD  SD_MOSI -> ESP32 GPIO23

// SPI MISO (data from SD to ESP32)
// SD  SD_MISO -> ESP32 GPIO19
// (TFT does NOT use MISO)


// TFT chip select
// TFT CS  -> ESP32 GPIO13

// SD card chip select
// SD CS   -> ESP32 GPIO5


 
// I2S Audio (MAX98357)
#define I2S_BCLK 26
#define I2S_LRC  25
#define I2S_DOUT 22
#define AMP_SD   27   // optional

//battery ADC
#define BAT_ADC 36

//RGB LED
#define RGB_PIN_R 33
#define RGB_PIN_G 32


//JOYSTICK
#define VERTICAL_PIN 34
#define HORIZONTAL_PIN 35
#define SELECT_PIN 4

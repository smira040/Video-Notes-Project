//Screen Pins
#define TFT_CS  5
#define TFT_RST 17 //TX2
#define TFT_DC  16 //RX2


//sd card pins
#define SD_CS 13

//SPI BUS pins
#define SPI_SCK  18
#define SPI_MISO 19
#define SPI_SDA 23 //mosi = sda

/* tft & sd card share the same
    clk
    mosi
*/

 
// I2S Audio (MAX98357)
#define I2S_LRC  25
#define I2S_BCLK 26
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

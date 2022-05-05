/*
 * OLED Temperature Meter and Fan Controller
 * Uses a DHT11 temperature sensor, library DHT
 * Display results on a 128 x 64 OLED display
 * Use library U8g2lib for display and Wire library for I2C
 */

// Include Libraries for display
#include <Wire.h>
#include <U8g2lib.h>
// Include DHT library for the sensor
#include "DHT.h"

// Set the pin for the DHT
#define DHTPIN D5
// Define the type of the sensor
#define DHTTYPE DHT11
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

// Define the display object, it represents the screen
U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);

#define timeDelay 2000

void display_prepare() {
display.setFont(u8g2_font_6x10_tf);
display.setFontRefHeightExtendedText(); //for drawing characters
display.setDrawColor(1); //1 is default, 0 means space around the character is lit up
display.setFontPosTop(); //character position in one line of text
display.setFontDirection(0); //direction of the text, 0 = 0°, 1 = 90°, 2 = 180° and 3 = 270°
}       

void setup() {
  // Start Wire library for I2C
  Wire.begin();
  // initialize OLED
  display.begin();
  display_prepare();
  display.clearBuffer();
  dht.begin(); //initialize sensor device
 }

void loop() {
  // Readings used for average
  const int numReadings = 5;
  // Set variables to zero
  float temp = 0;
  float avetemp = 0;
  float hum = 0;
  float avehum = 0;
  
  // Wait a few seconds to aloow sensor to stablize
  delay(timeDelay);
 
  display.drawStr(0, 0, "Temperatur(C):");
  display.drawStr(0, 15, "Humidity(%):");
  
  //  display.drawStr(0, 40, "Realtime Temp(C):");
  for (int i = 0; i < numReadings; i++) {
      temp += dht.readTemperature();
      hum += dht.readHumidity();
      delay(timeDelay);
  }
  // calculate the average
  avetemp = temp / numReadings;
  avehum = hum / numReadings;
  display.setCursor(100, 0);
  display.print(avetemp, 0);
  display.setCursor(100, 15);
  display.print(avehum, 0);
  display.sendBuffer();
  delay(timeDelay);
  display.clearBuffer();
  
  if (isnan(temp)) {
    display.clearBuffer();
    display.drawStr(0, 0, "DHT sensor failed!");
    display.sendBuffer();
    return;
  }
}

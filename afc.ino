/*
 * OLED Temperature Meter and Fan Controller
 * Uses a DHT11 temperature sensor, library DHT
 * Display results on a 128 x 64 OLED display
 * Use library U8g2lib for display and Wire library for I2C
 * When the temperature is higher then the maxTemp, turn on the Relay
 * When the temperature is lower then the minTemp, turn off the Relay
 */

// Include Libraries for display
#include <Wire.h>
#include <U8g2lib.h>
// Include DHT library for the sensor
#include "DHT.h"

// set the pin for relay (fans)
#define FANPIN D3
// Set the pin for the DHT
#define DHTPIN D5
// Define the type of the sensor
#define DHTTYPE DHT11
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);
// Define the display object, it represents the screen
U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);

// the frequence for checking the temp
#define timeDelay 5000
// temp for turn the fans on
float maxTemp = 30;
// temp for turn the fans off
float minTemp = 25;

// prepare the settings for the display
void displayPrepare() {
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
  displayPrepare();
  display.clearBuffer();
  // Initialize sensor device
  dht.begin();
  // setup the pin for relay
  pinMode(FANPIN, OUTPUT);
 }

void loop() {
  float temp = 0;
  float hum = 0;
  
  // Wait a few seconds to aloow sensor to stablize
  delay(timeDelay);
 
  display.drawStr(0, 0, "Temperatur(C):");
  display.drawStr(0, 15, "Humidity(%):");
  display.drawStr(0, 30, "Fans status:");

  temp = dht.readTemperature();
  hum = dht.readHumidity();
  display.setCursor(100, 0);
  display.print(temp, 0);
  display.setCursor(100, 15);
  display.print(hum, 0);
  if (temp >= maxTemp) {
    // turn on the relay
    digitalWrite(FANPIN, LOW);
    display.drawStr(100, 30, "ON");
  }
  else if (temp <= minTemp) {
    // turn off the relay
    digitalWrite(FANPIN, HIGH);
    display.drawStr(100, 30, "OFF");
  }
  else {
    display.drawStr(100, 30, "ON");
  }
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

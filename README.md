# Arduino_fan_controller

## Introduction

The aim of this project is to control several computer fans with Arduino, so that they can cool the air around a server.

Arduino gets temperature data from a temperature sensor and display the information on a OLED screen.

## Arduino

The type of Arduino is **ESP8266 NodeMCU V3 Lolin**

[ESP8266 NodeMCU Tutorial](https://diyi0t.com/esp8266-nodemcu-tutorial/)

## Breadboard Power Supply Module

For power the Arduino and other equipment without a computer

[How to use a breadboard power supply module](https://www.youtube.com/watch?v=1er6XQ-BMp4)

## Temperature sensor

The type of temperature sensor is **DHT11**

It is a temperature and humidity sensor:

- Vcc: power supply 3.5V to 5.5V
- out: outputs both Temperature and Humidity through serial Data
- Ground: connected to the ground of the circuit
- Temperature Range: 0°C to 50°C
- Humidity Range: 20% to 90%
- Accuracy: ±1°C and ±1%

[How to use DHT11 Sensor](https://components101.com/sensors/dht11-temperature-sensor)
[Measuring Temperature with Arduino](https://dronebotworkshop.com/arduino-temperature/)

## OLED Display

It is a 1.3 inch OLED I2C Screen.

- Power supply voltage: from 3.3V ti 5V
- Communication interface: I2C
- Pixel Color: White
- Operation temperature: from -20 to 70 C
- Dimensions: 36 x 34 x 3 mm [1.4 x 1.3 x 0.1 inch]

To use the screen, the library **U8g2** is used.

[u8g2 reference](https://github.com/olikraus/u8g2/wiki/u8g2reference#setcursor)

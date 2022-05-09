# Arduino_fan_controller

## Introduction

The aim of this project is to control several computer fans with Arduino, so that they can cool the air around a server.

Arduino gets temperature data from a temperature sensor and display the information on an OLED screen.

If the temperature is too high, then the Relay Module will be turned on so that the fans start spinning. Whe the temperature drops to a acceptable number, the Relay Module will be turned off so the fans will also stop.

## Arduino

The type of Arduino is **ESP8266 NodeMCU V3 Lolin**

[ESP8266 NodeMCU Tutorial](https://diyi0t.com/esp8266-nodemcu-tutorial/)

## Breadboard and Power Supply Module

I used a solderless breadboard for experting. If you want to make a project permanent version, you may want to transfer it to a perfboard or a printed circuit board.

[Breadboarding & Prototyping for Electronics, Arduino & Raspberry Pi](https://www.youtube.com/watch?v=Y3Kx2RlLXsY&list=WL&index=7)

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

## Fan Controller

I got three 12V fans from my old desktop. They have 3-pin connector, so technically I can only control the speed of them by changing the voltage supplied to it.

However, I choose to use the on/off control, because I don't have a mosfet. I have a relay module which was given to me along with the old Arduino. Therefore, with the relay I can just turn the fans on when it is too hot and turn off them when it is cool enough.

[How to Control Fan Speed](https://www.analog.com/en/analog-dialogue/articles/how-to-control-fan-speed.html)

I used a one channel relay module.

[Interface One Channel Relay Module with Arduino](https://lastminuteengineers.com/one-channel-relay-module-arduino-tutorial/)

# SPI_NeoPixel
This is a supplement library for [adafruit / Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel).

This library uses SPI MOSI instead of GPIO to control NeoPixel LED strap.

## Background

I tried out [KotaMeiwa/nepils](https://github.com/KotaMeiwa/nepils) that is a SPRESENSE support of Adafruit_NeoPixel. It is very nice library but SPRESENSE behaves strangely. In multi-core programming, the GPIO signal timings fluctuate even though interrupts are disabled. I don't know why. I therefore decided to use SPI instead of GPIO.

## Installation
### For HW connection

| LED strap    | Arduino board
| ----         | ---
| DIN (green)  | MOSI
| VCC (red)    | 5V
| GND (white)  | GND

### For Arduino IDE
**This library requires adafruit / Adafruit_NeoPixel.**

## API
*SPI_NeoPixel* is a inherited class of *Adafruit_NeoPixel*, therefore *SPI_NeoPixel* has same methods as *Adafruit_NeoPixel*.

additional APIs

- *uint8_t get_rgb_upper()*
- *void set_rgb_upper(uint8_t rgb_max)*

the following APIs is disabled

- *void setPin(int16_t p)*
- *void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w)*
- *void updateLength(uint16_t n)*
- *void updateType(neoPixelType t)*

## Copyright
Copyright (c) 2023 Bizan Nishimura

This project is forked from [KotaMeiwa/nepils](https://github.com/KotaMeiwa/nepils) that is a SPRESENSE support of Adafruit_NeoPixel, and SPI support is based on [Tamakichi/neopixel_spi.ino](https://gist.github.com/Tamakichi/b529a5c5792c9e6bea5efb8fdf4b0df1).

Special thanks to the great pioneers.

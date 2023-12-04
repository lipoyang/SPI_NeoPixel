#include <SPI_NeoPixel.h>

const uint16_t NUM_PIXELS = 16;

SPI_NeoPixel neopixel(NUM_PIXELS);

void setup()
{
	Serial.begin(115200);
	delay(1000);

	neopixel.begin();

	Serial.println("serial console start!");
}

void loop()
{
	//Blink
	neopixel.fill(Adafruit_NeoPixel::Color(64, 16, 0)); neopixel.show(), delay(500);
	neopixel.fill(Adafruit_NeoPixel::Color(64, 0, 0)); neopixel.show(), delay(500);
}

#pragma once
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class SPI_NeoPixel : public Adafruit_NeoPixel
{
private:
	uint8_t m_rgb_max;
	const uint32_t m_wait_cycles_reset;

public:
	SPI_NeoPixel(uint16_t led_num);
	~SPI_NeoPixel(){}

	uint8_t get_rgb_upper() { return m_rgb_max; }
	void set_rgb_upper(uint8_t rgb_max) {  m_rgb_max = rgb_max; }

public: //overwritten super class's method
	void begin(void);
	void show(void);

protected: //diabled super class's method
	void setPin(int16_t p){}
//	void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w){}
	void updateLength(uint16_t n){}
	void updateType(neoPixelType t){}

protected:
	inline uint8_t get_pixel_size(){ return (wOffset == rOffset? 3: 4); }
};


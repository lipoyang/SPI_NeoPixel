#include <Arduino.h>
#include <SPI.h>
#include <SPI_NeoPixel.h>

#define NEOSPI_0    0b11100000   // 1bit 0
#define NEOSPI_1    0b11111000   // 1bit 1
#define NEOSPI_RST  0b00000000   // RESET

///////////////////////
SPI_NeoPixel::SPI_NeoPixel(uint16_t led_num)
:	Adafruit_NeoPixel(led_num),
	m_rgb_max(255),
	m_wait_cycles_reset(1)
{
}

///////////////////////
void SPI_NeoPixel::begin(void)
{
	SPI.begin();
	
	clear();
	begun = true;
}

///////////////////////
void SPI_NeoPixel::show(void)
{
	while(!canShow()){}
	
	SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE1));
	
	SPI.transfer(NEOSPI_RST);
	
	const uint8_t pixel_size = get_pixel_size();
	if (pixel_size==3){
		noInterrupts();
		
		for(uint32_t pixel_ind = 0; pixel_ind < Adafruit_NeoPixel::numLEDs; ++pixel_ind){

			uint8_t* pixel_pt = Adafruit_NeoPixel::pixels + (pixel_ind * pixel_size);
			for(uint8_t rgb = 0; rgb < pixel_size; ++rgb){
				uint8_t pix_comp_val = min(pixel_pt[rgb], m_rgb_max);
				
				for (uint8_t j = 0; j < 8; j++) {
					SPI.transfer(pix_comp_val & (0x80>>j) ? NEOSPI_1:NEOSPI_0);
				}
			}
		}
		interrupts();
	}
	
	SPI.endTransaction();
}


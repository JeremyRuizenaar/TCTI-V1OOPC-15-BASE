#include "hwlib.hpp"


struct HC {
	hwlib::target::pin_out dc;
	hwlib::target::pin_out stcp;
	hwlib::target::pin_out shcp;
	hwlib::target::pin_in miso;
	hwlib::spi_bus_bit_banged_sclk_mosi_miso SPI;
	hwlib::hc595 Register;

	HC() :
		dc(hwlib::target::pins::d7),
		stcp(hwlib::target::pins::d6),
		shcp(hwlib::target::pins::d5),
		miso(hwlib::target::pins::d4),
		SPI(shcp, dc, miso),
		Register(SPI, stcp) { }
};

int main()
{
	HC chip;

	hwlib::target::pin_out led1 = hwlib::target::pin_out(hwlib::target::pins::d40);
	hwlib::target::pin_out led2 = hwlib::target::pin_out(hwlib::target::pins::d42);
	hwlib::target::pin_out led3 = hwlib::target::pin_out(hwlib::target::pins::d44);
	hwlib::target::pin_out led4 = hwlib::target::pin_out(hwlib::target::pins::d46);

	hwlib::target::pin_in knop1 = hwlib::target::pin_in(hwlib::target::pins::d15);
	hwlib::target::pin_in knop2 = hwlib::target::pin_in(hwlib::target::pins::d17);

	byte leds = 0b00000000;
	byte last = leds;
	bool err = false;

	while(1) {
		if(leds != last) {
			led1.set(((leds & 0b0001)?1:0));
			led4.set(((leds & 0b1000)?1:0));
			led2.set(((leds & 0b0010)?1:0));
			led3.set(((leds & 0b0100)?1:0));
			chip.Register.set(leds & 0b11110000);
			last = leds;
		}

		if(knop1.get() && !err) {
			leds = leds << 1;
			leds = leds + 0b0001;
			err = true;
			hwlib::wait_ms(80);
		} else if(knop2.get() && !err) {
			leds = leds >> 1;
			err = true;
			hwlib::wait_ms(80);
		} else if(!knop1.get() && !knop1.get() && err) {
			err = false;
			hwlib::wait_ms(80);
		}
	}
}
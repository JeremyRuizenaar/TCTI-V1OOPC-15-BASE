#include "hwlib.hpp"

int main(void)
{
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d40);
    auto led2 = hwlib::target::pin_out(hwlib::target::pins::d42);
    auto led3 = hwlib::target::pin_out(hwlib::target::pins::d44);
    auto led4 = hwlib::target::pin_out(hwlib::target::pins::d46);

    led1.set(0);
    led2.set(1);
    led3.set(1);
    led4.set(0);

    while (1)
    {
        led1.set(1);
        led3.set(0);
        hwlib::wait_ms(500);
        led1.set(0);
        led3.set(1);
        hwlib::wait_ms(500);
       led2.set(0);
        led4.set(1);
        hwlib::wait_ms(500);
		led2.set(1);
        led4.set(0);
        hwlib::wait_ms(500);
    }
}

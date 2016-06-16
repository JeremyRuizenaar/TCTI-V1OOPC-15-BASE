#include "hwlib.hpp"

void input(hwlib::port_out& leds, hwlib::pin_in& min, hwlib::pin_in& plus)
{
    unsigned int n = 0;
    while (1)
    {
        if (min.get() == 1 && n > 0) {
            n--;
        } else if (plus.get() == 1 && n < leds.number_of_pins()) {
            n++;
        }

        switch (n)
        {
            case 0: leds.set(0x0); break;
            case 1: leds.set(0x1); break;
            case 2: leds.set(0x3); break;
            case 4: leds.set(0x7); break;
            default: leds.set(0xF); break;
        }

        hwlib::wait_ms(250);
    }
}

int main(void)
{
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d40);
    auto led2 = hwlib::target::pin_out(hwlib::target::pins::d42);
    auto led3 = hwlib::target::pin_out(hwlib::target::pins::d44);
    auto led4 = hwlib::target::pin_out(hwlib::target::pins::d46);
    auto leds = hwlib::port_out_from_pins(led1, led2, led3, led4);

    auto btn1 = hwlib::target::pin_in(hwlib::target::pins::d15);
    auto btn2 = hwlib::target::pin_in(hwlib::target::pins::d17);

    input(leds, btn1, btn2);
}
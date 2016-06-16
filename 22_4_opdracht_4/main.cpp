#include "hwlib.hpp"

class decorator
{
private:
    hwlib::pin_in& knop1;
    hwlib::pin_in& knop2;
public:
    decorator(hwlib::pin_in& knop1, hwlib::pin_in& knop2) :
    knop1(knop1),
    knop2(knop2)
    {

    }

    bool get() {
        return (knop1.get() == 1 && knop2.get() == 1);
    }
};

int main(void)
{
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto led = hwlib::target::pin_out(hwlib::target::pins::d40);

    auto knop1 = hwlib::target::pin_in(hwlib::target::pins::d15);
    auto knop2 = hwlib::target::pin_in(hwlib::target::pins::d17);

    auto dec = decorator(knop1, knop2);

    while (1)
    {
        if (dec.get() == 1) {
            led.set(1);
        } else {
            led.set(0);
        }

        hwlib::wait_ms(200);
    }
}
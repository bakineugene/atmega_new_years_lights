#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define byte uint8_t

#include "tinyLED.h"

int main(int argc, char** argv) {

    tinyLED<3> led;

    led.setBrightness(150);

    DDRB |= (1 << 5);

    int step = 1;
    uint8_t color_r = 0;
    uint8_t color_g = 240;
    uint8_t color_b = 0;
    int delay = 24;
    while (1) {
        for (int l = 0; l < 100; ++l)  {
            if (step == 0) {
                if (color_r < 2) step = 1;
                color_g += 10;
                color_r -= 10;
            }
            if (step == 1) {
                if (color_g < 2) step = 2;
                color_b += 10;
                color_g -= 10;
            }
            if (step == 2) {
                if (color_b < 2) step = 0;
                color_r += 10;
                color_b -= 10;
            }
            led.sendRGB(color_r, color_g, color_b);

        }
        PORTB &= ~(1 << 5);
        for (int i = delay; i > 0; i -= 10) _delay_ms(1000);
        PORTB |=  (1 << 5);
        for (int i = delay; i > 0; i -= 10) _delay_ms(1000);
    }

}

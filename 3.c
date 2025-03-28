#include "mraa.h"
#include <stdio.h>
#include <unistd.h>

#define BUTTON_PIN 2
#define LED_PIN 13

int main()
{
    mraa_init();
    mraa_gpio_context button = mraa_gpio_init(BUTTON_PIN);
    mraa_gpio_dir(button, MRAA_GPIO_IN);
    mraa_gpio_context led = mraa_gpio_init(LED_PIN);
    mraa_gpio_dir(led, MRAA_GPIO_OUT);

    while (1) {
        if (mraa_gpio_read(button)) {
            mraa_gpio_write(led, 1);
        } else {
            mraa_gpio_write(led, 0);
        }
        usleep(100000);
    }

    mraa_gpio_close(led);
    mraa_gpio_close(button);
    mraa_deinit();
    return MRAA_SUCCESS;
}

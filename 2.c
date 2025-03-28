#include "mraa/gpio.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    mraa_gpio_context d_pin;


    mraa_init();

    d_pin = mraa_gpio_init(13);
    if (d_pin == NULL) {
        fprintf(stderr, "MRAA couldn't initialize GPIO 13\n");
        return MRAA_ERROR_UNSPECIFIED;
    }

    if (mraa_gpio_dir(d_pin, MRAA_GPIO_OUT) != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set GPIO direction\n");
        return MRAA_ERROR_UNSPECIFIED;
    }

    for (int i = 0; i < 1; i++) {
        printf("LED OFF\n");
        mraa_gpio_write(d_pin, 0);
        sleep(1);

        printf("LED ON\n");
        mraa_gpio_write(d_pin, 1);
        sleep(1);
    }

    mraa_gpio_close(d_pin);
    return MRAA_SUCCESS;
}

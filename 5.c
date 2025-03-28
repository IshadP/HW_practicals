#include "mraa/aio.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    mraa_aio_context adc_a0;
    uint16_t adc_value = 0;
    const int B = 4275;
    const int R0 = 100000;
    float temperature = 0.0;

    adc_a0 = mraa_aio_init(0);
    if (adc_a0 == NULL) {
        return 1;
    }

    for (int i = 10; i > 0; i--) {
        adc_value = mraa_aio_read(adc_a0);
        printf("ADC A0 read value: %d\n", adc_value);
        float R = 1023.0 / ((float)adc_value) - 1.0;
        R = R0 * R;
        temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15;
        printf("Temperature value: %.2f Degree Celsius \n", temperature);
        sleep(3);
    }

    mraa_aio_close(adc_a0);
    printf("Exiting .. Bbye!\n");
    return MRAA_SUCCESS;
}

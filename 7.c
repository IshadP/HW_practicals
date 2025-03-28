#include "grovelight.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    upm::GroveLight* light = new upm::GroveLight(0);

    for (int i = 10; i > 0; i--) {
        printf("Light value is %f which is roughly %d lux\n", light->raw_value(), light->value());
        fflush(stdout);
        sleep(2);
    }

    printf("Exiting ..bbye!");
    delete light;
    return 0;
}

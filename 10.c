#include "groverotary.hpp"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int is_running = 1;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        is_running = 0;
    }
}

int main() {
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\nCan't catch SIGINT\n");

    upm::GroveRotary* knob = new upm::GroveRotary(1);

    while (is_running) {
        float abs_value = knob->abs_value();
        float abs_deg = knob->abs_deg();
        float abs_rad = knob->abs_rad();

        float rel_value = knob->rel_value();
        float rel_deg = knob->rel_deg();
        float rel_rad = knob->rel_rad();

        printf("Absolute: %4d raw %5.2f deg %3.2f rad  Relative: %4d raw %5.2f deg %3.2f rad\n",
               (int16_t)abs_value, abs_deg, abs_rad,
               (int16_t)rel_value, rel_deg, rel_rad);

        sleep(1);
    }

    delete knob;
    return 0;
}

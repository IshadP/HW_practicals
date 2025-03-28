#include "mic.hpp"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

int is_running = 1;
uint16_t buffer[128];
upm::Microphone* mic = NULL;

void sig_handler(int signo)
{
    printf("got signal\n");
    if (signo == SIGINT) {
        is_running = 0;
    }
}

int main(int argc, char** argv)
{
    mic = new upm::Microphone(0);

    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");

    thresholdContext ctx;
    ctx.averageReading = 0;
    ctx.runningAverage = 0;
    ctx.averagedOver = 2;

    while (is_running) {
        int len = mic->getSampledWindow(2, 128, buffer);
        if (len) {
            int thresh = mic->findThreshold(&ctx, 30, buffer, len);
            mic->printGraph(&ctx);
            if (thresh) {
            }
        }
    }

    printf("exiting application\n");
    delete mic;
    return 0;
}

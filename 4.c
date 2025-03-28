#include <buzzer.hpp>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int chord[] = { DO, RE, FA, MI, SOL, LA, SI, DO, SI };
    upm::Buzzer* sound = new upm::Buzzer(5);

    printf("Volume = %f\n", sound->getVolume());
    sound->setVolume(0.1);
    printf("Volume = %f\n", sound->getVolume());
    fflush(stdout);

    printf("Playing notes, pausing for 0.1 seconds between notes...\n");
    fflush(stdout);

    for (int chord_ind = 0; chord_ind < 9; chord_ind++) {
        printf("%d\n", sound->playSound(chord[chord_ind], 500000));
        usleep(100000);
    }

    printf("Exiting, bbye!\n");
    delete sound;
    return 0;
}

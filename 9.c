#include "jhd1313m1.hpp"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    upm::Jhd1313m1* lcd = new upm::Jhd1313m1(0, 0x3E, 0x62);

    printf("Display text on LCD\n");
    lcd->setCursor(0, 0);
    lcd->write("25 ISHAD");
    lcd->setCursor(1, 2);
    lcd->write("HEY THERE!");

    printf("Sleeping for 10 seconds\n");
    sleep(10);

    printf("Starting Color loop...\n");
    for (int i = 5; i > 0; i--) {
        lcd->setColor(255, 0, 0);
        sleep(1);
        lcd->setColor(0, 255, 0);
        sleep(1);
        lcd->setColor(0, 0, 255);
        sleep(1);
    }

    printf("Exiting .. bbye!\n");
    delete lcd;
    return 0;
}

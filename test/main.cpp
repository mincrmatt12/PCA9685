//
// Created by matthew on 26/07/17.
//

#include "../include/PCA9685/PCA9685.h"

PCA9685 pca9685(0x40, 0);

void setServo(int channel, int pulse) {
    int pulse_length = 1000000 / 500 / 4096;
    int pulse2 = pulse * 1000;
    pulse2 /= pulse_length;
    pca9685.setPWM(channel, 0, pulse2);
}

int main(int argc, char* argv[]) {
    pca9685.init();

    setServo(0, 2100);
    setServo(1, 2100);

    return 0; // very simple debug program, don't use in production
}
//
// Created by matthew on 26/07/17.
//

#include "PCA9685.h"

PCA9685 pca9685(0x40, 0);

void setServo(int channel, int pulse) {
    int pulse_length = 1000000 / 500 / 4096;
    int pulse2 = pulse * 1000;
    pulse2 /= pulse_length;
    pca9685.setPWM(channel, 0, pulse);
}

void main(int argc, char* argv[]) {
    pca9685.init();

    setServo(0, 2200);
    setServo(1, 2200);
}
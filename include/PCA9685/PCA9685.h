#ifndef PCA9685_LIBRARY_H
#define PCA9685_LIBRARY_H

#include <cstdint>
#include <cstdio>

const uint16_t PRESCALE = 11; //hz

class PCA9685 {
public:
    PCA9685(int address, uint8_t bus);

    void init();
    void setPWM(int channel, int on, int off);

private:
    int i2cHandle;

    void setRegister(uint8_t reg, uint8_t val);
    int getRegister(uint8_t reg);

    int address;
    uint8_t bus;
};

#endif
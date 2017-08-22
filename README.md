# PCA9685
A library for using PCA9685 on linux via /dev/i2c-N. Does what it says on the tin, extremely simple API (looking to add a bit more functionality soon).

## API documentation

### Method documentation

- `PCA9685::PCA9685`: takes the address and bus number of the i2c device. For a PCA9685 on bus 0 and at the default address 0x40 use `PCA9685::PCA9685(0x40, 0)`
- `PCA9685::init`: call to acquire the i2c device and initialize the PCA9685. Seperate function call so you can construct the object statically and initialize it at a different time
- `PCA9685::setPWM`: set the PWM timings for channel `channel`. `on` and `off` are times at which the signal is high or low respectively.

### PWM information

The PCA9685's prescaler is set to a constant of 11 in this library, corresponding to 500hz. Since the PCA9685 is a 12bit device, `on` and `off` times are between 0-4096.
The following simple code can be used to make setting servo pulse widths easier (in 1us increments):

```c++
void setServo(int channel, int pulse) {
    int pulse_length = 1000000 / 500 / 4096;
    int pulse2 = pulse * 1000;
    pulse2 /= pulse_length;
    pca9685.setPWM(channel, 0, pulse);
}
```

## Including in your projects

Using this in non-ros/non-catkin environments is a use case that is coming soon, but if you are already using ros, simply add this package to
your repository! This task is simple with `wstool`, so use that. After doing that, the headers for using this library are located at `<PCA9685/PCA9685.h>`. Happy tinkering!

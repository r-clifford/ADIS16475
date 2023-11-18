#include <iostream>

#include "ADIS16475.h"
#include "pigpio.h"

int main() {
  if (gpioInitialise() < 0) {
    std::cout << "Unable to initialize PiGPIO" << std::endl;
    return 1;
  }

  return 0;
}
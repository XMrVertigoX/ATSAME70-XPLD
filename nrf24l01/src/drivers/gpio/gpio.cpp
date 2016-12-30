/*
 * gpiodrv.cpp
 *
 *  Created on: 29.12.2016
 *      Author: caspa
 */

#include <drivers/gpio/gpio.hpp>

namespace xXx {

Gpio::Gpio() {}

Gpio::~Gpio() {}

bool Gpio::read() {
    return false;
}

void Gpio::toggle() {}

void Gpio::write(bool state) {}

void Gpio::disableInterrupt() {}

void Gpio::enableInterrupt(IGpio_Callback_t cb, void *user) {}

} /* namespace xXx */

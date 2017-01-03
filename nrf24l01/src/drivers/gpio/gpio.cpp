#include <arm_math.h>

#include <asf.h>

#include <xXx/utils/logging.hpp>

#include "gpio.hpp"

namespace xXx {

Gpio::Gpio(ioport_pin_t pin) : _pin(pin) {}

Gpio::~Gpio() {}

void Gpio::init(ioport_direction dir) {
    ioport_enable_pin(_pin);
    ioport_set_pin_dir(_pin, dir);
}

void Gpio::clear() {
    pio_set_pin_low(_pin);
}

bool Gpio::get() {
    return (pio_get_pin_value(_pin));
}

void Gpio::set() {
    pio_set_pin_high(_pin);
}

void Gpio::toggle() {
    pio_toggle_pin(_pin);
}

void Gpio::disableInterrupt() {
    pio_disable_pin_interrupt(_pin);
}

void Gpio::enableInterrupt(IGpio_Callback_t callback, void *user) {
    uint32_t group_id = pio_get_pin_group_id(_pin);

    _callback[0][_pin] = callback;
    _user[0][_pin]     = user;

    pio_handler_set_pin(_pin, PIN_PUSHBUTTON_1_ATTR, staticISR);
    pio_enable_pin_interrupt(_pin);
}

IGpio_Callback_t Gpio::_callback[5][32];
void *Gpio::_user[5][32];

void Gpio::staticISR(uint32_t group_id, uint32_t group_mask) {
    uint32_t pinIndex = 0;

    if (group_mask > 0) {
        while (group_mask >>= 1) {
            pinIndex++;
        }
    }

    if (Gpio::_callback[0][pinIndex]) {
        Gpio::_callback[0][pinIndex](Gpio::_user[0][pinIndex]);
    }
}

} /* namespace xXx */

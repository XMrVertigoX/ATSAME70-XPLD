#include <asf.h>

#include <xXx/utils/logging.hpp>

#include "gpio.hpp"

namespace xXx {

static inline int8_t groupId2groupIndex(uint32_t groupId) {
    switch (groupId) {
        case ID_PIOA: {
            return (0);
        } break;
        case ID_PIOB: {
            return (1);
        } break;
        case ID_PIOC: {
            return (2);
        } break;
        case ID_PIOD: {
            return (3);
        } break;
        case ID_PIOE: {
            return (4);
        } break;
    }

    return (-1);
}

IGpio_Callback_t Gpio::_callback[160];
void *Gpio::_user[160];

Gpio::Gpio(ioport_pin_t pin) : _pin(pin) {}

Gpio::~Gpio() {}

void Gpio::init(ioport_direction dir) {
    ioport_enable_pin(_pin);
    ioport_set_pin_dir(_pin, dir);
}

void Gpio::clear() {
    ioport_set_pin_level(_pin, false);
}

bool Gpio::get() {
    return (ioport_get_pin_level(_pin));
}

void Gpio::set() {
    ioport_set_pin_level(_pin, true);
}

void Gpio::toggle() {
    ioport_toggle_pin_level(_pin);
}

void Gpio::disableInterrupt() {
    pio_disable_pin_interrupt(_pin);
}

void Gpio::enableInterrupt(IGpio_Callback_t callback, void *user) {
    // Configuration for button use
    // pio_handler_set_pin(_pin, (PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE), interruptFunction);
    pio_handler_set_pin(_pin, PIO_IT_FALL_EDGE, interruptFunction);

    _callback[_pin] = callback;
    _user[_pin]     = user;

    pio_enable_pin_interrupt(_pin);
}

void Gpio::interruptFunction(uint32_t groupId, uint32_t groupMask) {
    int8_t groupIndex = groupId2groupIndex(groupId);
    int8_t pinId      = __builtin_ctz(groupMask);
    int8_t pinIndex   = pinId | (groupIndex < 5);

    if (groupIndex < 0) {
        return;
    }

    if (_callback[pinIndex] != NULL) {
        _callback[pinIndex](_user[pinIndex]);
    }
}

} /* namespace xXx */

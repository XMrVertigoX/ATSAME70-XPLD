#include <arm_math.h>

#include <asf.h>

#include <xXx/utils/logging.hpp>

#include "gpio.hpp"

namespace xXx {

static inline int groupId2groupIndex(uint32_t groupId) {
    switch (groupId) {
        case ID_PIOA: return (0); break;
        case ID_PIOB: return (1); break;
        case ID_PIOC: return (2); break;
        case ID_PIOD: return (3); break;
        case ID_PIOE: return (4); break;
    }

    return (-1);
}

IGpio_Callback_t Gpio::_callback[5][32];
void *Gpio::_user[5][32];

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
    int groupIndex = groupId2groupIndex(pio_get_pin_group_id(_pin));

    if (groupIndex < 0) {
        return;
    }

    _callback[groupIndex][_pin] = callback;
    _user[groupIndex][_pin]     = user;

    // Todo:
    // pio_handler_set_pin(_pin, (PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE), staticISR);
    pio_handler_set_pin(_pin, PIO_IT_FALL_EDGE, staticISR);
    pio_enable_pin_interrupt(_pin);
}

void Gpio::staticISR(uint32_t groupId, uint32_t groupMask) {
    int groupIndex   = groupId2groupIndex(groupId);
    uint8_t pinIndex = 0;

    if (groupIndex < 0) {
        return;
    }

    if (groupMask > 0) {
        while (groupMask >>= 1) {
            pinIndex++;
        }
    }

    if (_callback[groupIndex][pinIndex]) {
        _callback[groupIndex][pinIndex](_user[groupIndex][pinIndex]);
    }
}

} /* namespace xXx */

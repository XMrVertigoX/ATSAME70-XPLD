#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <asf.h>

#include <xXx/interfaces/igpio.hpp>

namespace xXx {

class Gpio : public IGpio {
   private:
    ioport_pin_t _pin;

    static void interruptFunction(uint32_t group_id, uint32_t group_mask);
    static IGpio_Callback_t _callback[160];
    static void *_user[160];

   public:
    Gpio(ioport_pin_t pin);
    virtual ~Gpio();
    void init(ioport_direction dir);

    /* General functionality */
    void clear();
    bool get();
    void set();
    void toggle();

    /* Interrupt control */
    void disableInterrupt();
    void enableInterrupt(IGpio_Callback_t callback, void *user);
};

typedef Gpio *Gpio_Handle_t;

} /* namespace xXx */

#endif /* GPIO_HPP_ */

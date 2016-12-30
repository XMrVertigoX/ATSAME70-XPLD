/*
 * gpiodrv.hpp
 *
 *  Created on: 29.12.2016
 *      Author: caspa
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <xXx/interfaces/igpio.hpp>

namespace xXx {

class Gpio : public IGpio {
  public:
    Gpio();
    virtual ~Gpio();

    /* General functionality */
    bool read();
    void toggle();
    void write(bool state);

    /* Interrupt control */
    void disableInterrupt();
    void enableInterrupt(IGpio_Callback_t cb, void *user);
};

} /* namespace xXx */

#endif /* GPIO_HPP_ */

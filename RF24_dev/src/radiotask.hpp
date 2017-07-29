#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/rf24/rf24.hpp>
#include <xXx/components/wireless/rf24/rf24_types.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/circularbuffer.hpp>

#include "drivers/gpio.hpp"

class RadioTask : public xXx::SimpleTask {
   private:
    xXx::RF24 &receiver;
    drivers::Gpio led;

   public:
    RadioTask(xXx::RF24 &receiver);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

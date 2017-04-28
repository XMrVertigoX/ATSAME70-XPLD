#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>

#include "drivers/gpio/gpio.hpp"

using namespace xXx;

class RadioTask : public SimpleTask {
   private:
    RF24_ESB &_receiver;
    Gpio _led;
    Queue<RF24_Package_t> _rxQueue;

   public:
    RadioTask(RF24_ESB &receiver);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

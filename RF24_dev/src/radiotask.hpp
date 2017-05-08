#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/components/wireless/nrf24l01p/nrf24l01p_types.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>

#include "drivers/gpio/gpio.hpp"

using namespace xXx;

class RadioTask : public SimpleTask {
   private:
    RF24_ESB &receiver;
    Gpio led;
    Queue<RF24_DataPackage_t> rxQueue;

   public:
    RadioTask(RF24_ESB &receiver);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

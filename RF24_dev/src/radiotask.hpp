#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/rf24/rf24.hpp>
#include <xXx/components/wireless/rf24/rf24_types.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>

#include "drivers/gpio/gpio.hpp"

using namespace xXx;

class RadioTask : public SimpleTask {
   private:
    RF24 &receiver;
    Gpio led;
    Queue<RF24_DataPackage_t> rxQueue;

   public:
    RadioTask(RF24 &receiver);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>

using namespace xXx;

class RadioTask : public SimpleTask {
   private:
    nRF24L01P_ESB &_receiver;
    Queue<uint8_t> _queue;

   public:
    RadioTask(nRF24L01P_ESB &receiver);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

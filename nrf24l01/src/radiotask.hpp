#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/RF24/nRF24L01.hpp>
#include <xXx/os/arduinotask.hpp>

using namespace xXx;

class RadioTask : public ArduinoTask {
  private:
    nRF24L01 &_rf24;

  public:
    RadioTask(nRF24L01 &rf24);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

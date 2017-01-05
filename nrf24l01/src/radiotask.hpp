#ifndef RADIOTASK_HPP_
#define RADIOTASK_HPP_

#include <xXx/components/wireless/RF24/RF24.hpp>
#include <xXx/os/arduinotask.hpp>

using namespace xXx;

class RadioTask : public ArduinoTask {
  private:
    RF24 &_rf24;

  public:
    RadioTask(RF24 &rf24);
    ~RadioTask();
    void setup();
    void loop();
};

#endif /* RADIOTASK_HPP_ */

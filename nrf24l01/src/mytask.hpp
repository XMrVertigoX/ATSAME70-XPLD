#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/os/arduinotask.hpp>
#include <xXx/templates/singleton.hpp>

#include <drivers/spi/spicontroller.hpp>

using namespace xXx;

class MyTask : public ArduinoTask {
  public:
    MyTask();
    ~MyTask();
    void setup();
    void loop();
};

#endif /* MYTASK_HPP_ */

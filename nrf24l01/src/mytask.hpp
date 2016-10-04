#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/os/arduinotask.hpp>
#include <xXx/templates/singleton.hpp>

#include <drivers/spi/spicontroller.hpp>

using namespace xXx;

class MyTask : public ArduinoTask {
  public:
    MyTask(uint16_t stack, UBaseType_t priority);
    ~MyTask();
    void setup();
    void loop();
};

#endif /* MYTASK_HPP_ */

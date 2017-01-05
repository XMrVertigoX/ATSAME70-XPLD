#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/os/arduinotask.hpp>

#include <drivers/gpio/gpio.hpp>
#include <drivers/spi/spidevice.hpp>

#include <drivers/spi/spicontroller.hpp>

using namespace xXx;

class MyTask : public ArduinoTask {
  private:
    RF24 &_rf24;

  public:
    MyTask(RF24 &rf24);
    ~MyTask();
    void setup();
    void loop();
};

#endif /* MYTASK_HPP_ */

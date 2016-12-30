#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/os/arduinotask.hpp>

#include <drivers/gpio/gpio.hpp>
#include <drivers/spi/spidevice.hpp>

#include <drivers/spi/spicontroller.hpp>

using namespace xXx;

class MyTask : public ArduinoTask {
  private:
    SpiDevice &_spi;
    Gpio &_ce;
    Gpio &_irq;

  public:
    MyTask(SpiDevice &spi, Gpio &ce, Gpio &irq);
    ~MyTask();
    void setup();
    void loop();
};

#endif /* MYTASK_HPP_ */

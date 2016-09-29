#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/templates/singleton.hpp>
#include <xXx/utils/arduinotask.hpp>

#include <drivers/spi/spicontroller.hpp>

using namespace xXx;

class MyTask : public Singleton<MyTask>, public ArduinoTask {
    friend class Singleton<MyTask>;

  public:
    void setup();
    void loop();

  private:
    MyTask() = default;
    ~MyTask() = default;
};

#endif /* MYTASK_HPP_ */

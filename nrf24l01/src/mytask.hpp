#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/util/arduinotask.hpp>
#include <xXx/util/singleton.hpp>

#include "driver/spidevice.hpp"

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

#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/utils/arduinotask.hpp>
#include <xXx/utils/singleton.hpp>

#include <drivers/spi/spicontroller.hpp>

class BlinkTask : public Singleton<BlinkTask>, public ArduinoTask {
    friend class Singleton<BlinkTask>;

   public:
    void setup();
    void loop();

   private:
    BlinkTask() = default;
    ~BlinkTask() = default;
};

#endif /* MYTASK_HPP_ */

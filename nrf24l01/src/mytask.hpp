#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/templates/singleton.hpp>
#include <xXx/utils/arduinotask.hpp>

#include <drivers/spi/spicontroller.hpp>

using namespace xXx;

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

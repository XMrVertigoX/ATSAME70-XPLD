#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <lib/services/spidrv.hpp>
#include <lib/util/iarduinotask.hpp>

class MyTask : public IArduinoTask {
   private:
    SpiDrv &_spi;
    SpiDrv_Device_t _spiDevice;

   public:
    MyTask(SpiDrv spi);
    ~MyTask();
    void setup();
    void loop();
};

#endif /* MYTASK_HPP_ */

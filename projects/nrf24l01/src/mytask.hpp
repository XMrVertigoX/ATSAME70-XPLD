#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include "lib/driver/spidrv.hpp"
#include "lib/nrf24l01/nrf24l01p.hpp"
#include "lib/util/iarduino.hpp"

class MyTask : public IArduino {
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

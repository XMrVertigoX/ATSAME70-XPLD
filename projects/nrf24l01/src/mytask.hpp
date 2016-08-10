#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <lib/components/wireless/nrf24l01p/nrf24l01p.hpp>
#include <lib/services/spidrv.hpp>
#include <lib/util/iarduino.hpp>

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

#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <components/wireless/nrf24l01p/nrf24l01p.hpp>
#include <services/spidrv.hpp>
#include <util/iarduinotask.hpp>

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

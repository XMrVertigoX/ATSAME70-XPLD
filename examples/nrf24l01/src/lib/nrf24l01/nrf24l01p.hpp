#ifndef NRF24L01P_HPP_
#define NRF24L01P_HPP_

#include "spidrv.hpp"

class nRF24L01P {
   private:
    SpiDrv &_spi;
    SpiDrv_Device_t &_device;
    uint8_t readRegister(uint8_t reg, uint8_t &buf);
    uint8_t writeRegister(uint8_t reg, uint8_t val);

   public:
    nRF24L01P(SpiDrv &spi, SpiDrv_Device_t &device);
    ~nRF24L01P();
    void powerDown();
    void powerUp();
};

#endif /* NRF24L01P_HPP_ */

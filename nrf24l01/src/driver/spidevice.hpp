#ifndef SPIDRV_SAME70_HPP_
#define SPIDRV_SAME70_HPP_

#include <asf.h>

#include <xXx/drivers/genericspi.hpp>

class SpiDevice : public GenericSpi {
   private:
    void configurePeripheralChipSelectPin();

    Spi *_spi;
    uint32_t _peripheral;

   public:
    SpiDevice(Spi *spi, uint32_t peripheral, uint32_t mode, uint32_t baudRate);
    ~SpiDevice();

    // GenericSpi
    void transmit(uint8_t misoBytes[], uint8_t mosiBytes[], size_t numBytes);
};

#endif /* SPIDRV_SAME70_HPP_ */

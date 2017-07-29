#ifndef SPIDEVICE_HPP_
#define SPIDEVICE_HPP_

#include <asf.h>

#include <FreeRTOS.h>
#include <semphr.h>

#include <xXx/interfaces/ispi.hpp>

namespace drivers {

class SpiDevice : public xXx::ISpi {
   private:
    void configurePeripheralChipSelectPin();
    void configureSpiPins();
    void disableChipSelect();
    void enableChipSelect();
    void enableSpiMasterMode(uint32_t delayBetweenChipSelect = 0);

    Spi *_spi;
    uint32_t _peripheral;

   public:
    SpiDevice(Spi *spi, uint32_t peripheral);
    ~SpiDevice();

    void init(uint32_t mode, uint32_t baudRate);

    uint8_t transmit_receive(uint8_t txBytes[], uint8_t rxBytes[], size_t numBytes);
};

} /* namespace */

#endif /* SPIDEVICE_HPP_ */

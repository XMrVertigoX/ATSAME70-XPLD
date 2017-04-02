#ifndef SPIDEVICE_HPP_
#define SPIDEVICE_HPP_

#include <asf.h>

#include <FreeRTOS.h>
#include <semphr.h>

#include <xXx/interfaces/ispi.hpp>

using namespace xXx;

class SpiDevice : public ISpi {
   private:
    void configurePeripheralChipSelectPin();
    void enableChipSelect();
    void disableChipSelect();

    Spi *_spi;
    uint32_t _peripheral;

   public:
    SpiDevice(Spi *spi, uint32_t peripheral);
    ~SpiDevice();

    void init(uint32_t mode, uint32_t baudRate);

    uint8_t transmit_receive(Queue<uint8_t> &queue);
};

#endif /* SPIDEVICE_HPP_ */

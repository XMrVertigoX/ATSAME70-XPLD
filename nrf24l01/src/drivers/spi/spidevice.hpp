#ifndef SPIDEVICE_HPP_
#define SPIDEVICE_HPP_

#include <asf.h>

#include <xXx/interfaces/ispi.hpp>

using namespace xXx;

class SpiDevice : public ISpi {
  private:
    void configurePeripheralChipSelectPin();

    Spi *_spi;
    uint32_t _peripheral;

  public:
    SpiDevice(Spi *spi, uint32_t peripheral);
    ~SpiDevice();

    void init(uint32_t mode, uint32_t baudRate);

    uint8_t transmit(uint8_t mosiBytes[], size_t mosiNumBytes,
                     ISpi_TransmitCallback_t callback, void *user);
};

#endif /* SPIDEVICE_HPP_ */

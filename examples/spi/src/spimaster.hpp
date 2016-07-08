#ifndef SPIMASTER_HPP_
#define SPIMASTER_HPP_

#include <asf.h>

enum Spi_Mode_t {
    spiMode0,
    spiMode1,
    spiMode2,
    spiMode3
};

enum Spi_Peripheral_t {
    spiPeripheral0,
    spiPeripheral1,
    spiPeripheral2,
    spiPeripheral3
};

struct Spi_Device_t {
    Spi_Peripheral_t peripheral;
};

class SpiMaster {
 private:
    void enablePins();
    void disableChipSelect(Spi_Device_t &device);
    void enableChipSelect(Spi_Device_t &device);

    Spi *_spi;
    bool initialized = false;

 public:
    SpiMaster(Spi *spi);
    ~SpiMaster();
    uint8_t initialize();
    uint8_t setupDevice(Spi_Device_t &device, Spi_Peripheral_t peripheral,
                        Spi_Mode_t mode, uint32_t baudRate);
    uint8_t transceive(Spi_Device_t &device, uint8_t txBytes[],
                       uint8_t rxBytes[], size_t numBytes);
};

#endif /* SPIMASTER_HPP_ */

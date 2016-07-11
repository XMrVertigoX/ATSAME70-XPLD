#ifndef SPIMASTER_HPP_
#define SPIMASTER_HPP_

#include <asf.h>

enum Spi_Mode_t { SpiMode0, SpiMode1, SpiMode2, SpiMode3 };

enum Spi_Peripheral_t {
    SpiPeripheral0,
    SpiPeripheral1,
    SpiPeripheral2,
    SpiPeripheral3
};

struct Spi_Device_t {
    Spi_Peripheral_t peripheral;
};

class SpiMaster {
   private:
    void enableChipSelectPin(Spi_Peripheral_t peripheral);
    void enableSpiPins();
    void disableChipSelect(Spi_Peripheral_t peripheral);
    void enableChipSelect(Spi_Peripheral_t peripheral);

    Spi *_spi;
    bool initialized = false;

   public:
    SpiMaster(Spi *spi);
    ~SpiMaster();
    uint8_t initialize(uint32_t delay = 0);
    uint8_t setupDevice(Spi_Device_t &device, Spi_Peripheral_t peripheral,
                        Spi_Mode_t mode, uint32_t baudRate);
    uint8_t transceive(Spi_Device_t &device, uint8_t misoBytes[],
                       uint8_t mosiBytes[], size_t numBytes);
};

#endif /* SPIMASTER_HPP_ */

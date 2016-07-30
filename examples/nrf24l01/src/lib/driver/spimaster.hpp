#ifndef SPIMASTER_HPP_
#define SPIMASTER_HPP_

#include <asf.h>

enum Spi_Mode_t {
    Spi_Mode_0,
    Spi_Mode_1,
    Spi_Mode_2,
    Spi_Mode_3,
};

enum Spi_Peripheral_t {
    Spi_Peripheral_0,
    Spi_Peripheral_1,
    Spi_Peripheral_2,
    Spi_Peripheral_3,
};

struct Spi_Device_t {
    Spi_Peripheral_t peripheral;
};

class SpiMaster {
   private:
    void configurePeripheralChipSelectPin(Spi_Peripheral_t peripheral);
    void configureSpiPins();
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

#ifndef SPIDRV_HPP_
#define SPIDRV_HPP_

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

class SpiDrv {
   private:
    void configurePeripheralChipSelectPin(Spi_Peripheral_t peripheral);
    void configurePins();
    void disableChipSelect(Spi_Peripheral_t peripheral);
    void enableChipSelect(Spi_Peripheral_t peripheral);

    Spi *_spi;

   public:
    SpiDrv(Spi *spi);
    ~SpiDrv();
    uint8_t enableMasterMode(uint32_t delay = 0);
    uint8_t enableSlaveMode();
    uint8_t setupDevice(Spi_Device_t &device, Spi_Peripheral_t peripheral,
                        Spi_Mode_t mode, uint32_t baudRate);
    uint8_t transceive(Spi_Device_t &device, uint8_t misoBytes[],
                       uint8_t mosiBytes[], size_t numBytes);
};

#endif /* SPIDRV_HPP_ */

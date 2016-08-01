#ifndef SPIDRV_HPP_
#define SPIDRV_HPP_

#include <asf.h>

enum SpiDrv_Mode_t {
    SpiDrv_Mode_0,
    SpiDrv_Mode_1,
    SpiDrv_Mode_2,
    SpiDrv_Mode_3,
};

enum SpiDrv_Peripheral_t {
    SpiDrv_Peripheral_0,
    SpiDrv_Peripheral_1,
    SpiDrv_Peripheral_2,
    SpiDrv_Peripheral_3,
};

struct SpiDrv_Device_t {
    SpiDrv_Peripheral_t peripheral;
};

class SpiDrv {
   private:
    void configurePeripheralChipSelectPin(SpiDrv_Peripheral_t peripheral);
    void configurePins();
    void disableChipSelect(SpiDrv_Peripheral_t peripheral);
    void enableChipSelect(SpiDrv_Peripheral_t peripheral);

    Spi *_spi;

   public:
    SpiDrv(Spi *spi);
    ~SpiDrv();
    uint8_t enableMasterMode(uint32_t delayBetweenChipSelect = 0);
    uint8_t enableSlaveMode();
    uint8_t setupDevice(SpiDrv_Device_t &device, SpiDrv_Peripheral_t peripheral,
                        SpiDrv_Mode_t mode, uint32_t baudRate);
    uint8_t transceive(SpiDrv_Device_t &device, uint8_t misoBytes[],
                       uint8_t mosiBytes[], size_t numBytes);
};

#endif /* SPIDRV_HPP_ */

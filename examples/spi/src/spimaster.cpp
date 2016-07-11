#include <cassert>
#include <cstdint>

#include "spimaster.hpp"

#define polarityMask 0b00000010
#define phaseMask 0b00000001
#define placeholder 0xFF
#define waitUntil(x) while (!x)

static void setPinMode(ioport_pin_t pin, ioport_mode_t mode) {
    ioport_set_pin_mode(pin, mode);
    ioport_disable_pin(pin);
}

void SpiMaster::enableChipSelectPin(Spi_Peripheral_t peripheral) {
    if (SPI0 == _spi) {
        switch (peripheral) {
            case SpiPeripheral0:
                setPinMode(SPI0_NPCS0_GPIO, SPI0_NPCS0_FLAGS);
                break;
            case SpiPeripheral1:
                setPinMode(SPI0_NPCS1_GPIO, SPI0_NPCS1_FLAGS);
                break;
            case SpiPeripheral2:
                setPinMode(SPI0_NPCS2_GPIO, SPI0_NPCS2_FLAGS);
                break;
            case SpiPeripheral3:
                setPinMode(SPI0_NPCS3_GPIO, SPI0_NPCS3_FLAGS);
                break;
        }
    }
}

void SpiMaster::enableSpiPins() {
    if (SPI0 == _spi) {
        setPinMode(SPI0_MISO_GPIO, SPI0_MISO_FLAGS);
        setPinMode(SPI0_MOSI_GPIO, SPI0_MOSI_FLAGS);
        setPinMode(SPI0_SPCK_GPIO, SPI0_SPCK_FLAGS);
    }
}

SpiMaster::SpiMaster(Spi *spi) : _spi(spi) {}

SpiMaster::~SpiMaster() {
    spi_disable(_spi);
    spi_disable_clock(_spi);
}

uint8_t SpiMaster::initialize(uint32_t delay) {
    enableSpiPins();

    spi_enable_clock(_spi);
    spi_reset(_spi);
    spi_set_master_mode(_spi);
    spi_disable_mode_fault_detect(_spi);
    spi_disable_loopback(_spi);
    spi_set_fixed_peripheral_select(_spi);
    spi_disable_peripheral_select_decode(_spi);
    spi_set_delay_between_chip_select(_spi, delay);
    spi_enable(_spi);

    initialized = true;

    return 0;
}

uint8_t SpiMaster::setupDevice(Spi_Device_t &device,
                               Spi_Peripheral_t peripheral, Spi_Mode_t mode,
                               uint32_t baudRate) {
    int16_t baudRateDivider =
        spi_calc_baudrate_div(baudRate, sysclk_get_cpu_hz());
    assert(baudRateDivider > 0);

    enableChipSelectPin(peripheral);

    spi_set_transfer_delay(_spi, peripheral, 0, 0);
    spi_set_bits_per_transfer(_spi, peripheral, SPI_CSR_BITS_8_BIT);
    spi_set_baudrate_div(_spi, peripheral, baudRateDivider);
    spi_configure_cs_behavior(_spi, peripheral, SPI_CS_KEEP_LOW);
    spi_set_clock_polarity(_spi, peripheral, (mode & polarityMask) >> 1);
    spi_set_clock_phase(_spi, peripheral, ((~mode) & phaseMask));

    device.peripheral = peripheral;

    return 0;
}

void SpiMaster::disableChipSelect(Spi_Peripheral_t peripheral) {
    spi_set_peripheral_chip_select_value(_spi, (1 << peripheral));
    spi_set_lastxfer(_spi);
}

void SpiMaster::enableChipSelect(Spi_Peripheral_t peripheral) {
    spi_set_peripheral_chip_select_value(_spi, ~(1 << peripheral));
}

uint8_t SpiMaster::transceive(Spi_Device_t &device, uint8_t misoBuffer[],
                              uint8_t mosiBuffer[], size_t length) {
    assert(initialized);

    if (0 == length || (NULL == misoBuffer && NULL == mosiBuffer)) {
        return 1;
    }

    enableChipSelect(device.peripheral);

    for (int i = 0; i < length; i++) {
        waitUntil(spi_is_tx_ready(_spi));

        if (NULL != mosiBuffer) {
            spi_put(_spi, mosiBuffer[i]);
        } else {
            spi_put(_spi, placeholder);
        }

        if (NULL != misoBuffer) {
            waitUntil(spi_is_rx_ready(_spi));
            misoBuffer[i] = spi_get(_spi);
        }
    }

    waitUntil(spi_is_tx_empty(_spi));

    disableChipSelect(device.peripheral);

    return 0;
}

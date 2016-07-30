#include <cassert>
#include <cstdint>

#include <asf.h>

#include "spimaster.hpp"

#define POLARITY_MASK 0b00000010
#define PHASE_MASK 0b00000001
#define PLACEHOLDER 0xFF
#define WAIT_UNTIL(x) while (!x)

static void setPinMode(ioport_pin_t pin, ioport_mode_t mode) {
    ioport_set_pin_mode(pin, mode);
    ioport_disable_pin(pin);
}

void SpiDrv::configurePins() {
    if (SPI0 == _spi) {
        setPinMode(SPI0_MISO_GPIO, SPI0_MISO_FLAGS);
        setPinMode(SPI0_MOSI_GPIO, SPI0_MOSI_FLAGS);
        setPinMode(SPI0_SPCK_GPIO, SPI0_SPCK_FLAGS);
    }
}

void SpiDrv::configurePeripheralChipSelectPin(Spi_Peripheral_t peripheral) {
    if (SPI0 == _spi) {
        switch (peripheral) {
            case Spi_Peripheral_0:
                setPinMode(SPI0_NPCS0_GPIO, SPI0_NPCS0_FLAGS);
                break;
            case Spi_Peripheral_1:
                setPinMode(SPI0_NPCS1_GPIO, SPI0_NPCS1_FLAGS);
                break;
            case Spi_Peripheral_2:
                setPinMode(SPI0_NPCS2_GPIO, SPI0_NPCS2_FLAGS);
                break;
            case Spi_Peripheral_3:
                setPinMode(SPI0_NPCS3_GPIO, SPI0_NPCS3_FLAGS);
                break;
        }
    }
}

void SpiDrv::enableChipSelect(Spi_Peripheral_t peripheral) {
    spi_set_peripheral_chip_select_value(_spi, ~(1 << peripheral));
}

void SpiDrv::disableChipSelect(Spi_Peripheral_t peripheral) {
    spi_set_peripheral_chip_select_value(_spi, (1 << peripheral));
}

// ----- Public API -----------------------------------------------------------

SpiDrv::SpiDrv(Spi *spi) : _spi(spi) {}

SpiDrv::~SpiDrv() {
    spi_disable(_spi);
    spi_disable_clock(_spi);
}

uint8_t SpiDrv::enableMasterMode(uint32_t delay) {
    configurePins();

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

    return EXIT_SUCCESS;
}

uint8_t SpiDrv::setupDevice(Spi_Device_t &device,
                               Spi_Peripheral_t peripheral, Spi_Mode_t mode,
                               uint32_t baudRate) {
    int16_t baudRateDivider =
        spi_calc_baudrate_div(baudRate, sysclk_get_cpu_hz());
    assert(baudRateDivider > 0);

    configurePeripheralChipSelectPin(peripheral);

    spi_set_transfer_delay(_spi, peripheral, 0, 0);
    spi_set_bits_per_transfer(_spi, peripheral, SPI_CSR_BITS_8_BIT);
    spi_set_baudrate_div(_spi, peripheral, baudRateDivider);
    spi_configure_cs_behavior(_spi, peripheral, SPI_CS_KEEP_LOW);
    spi_set_clock_polarity(_spi, peripheral, (mode & POLARITY_MASK) >> 1);
    spi_set_clock_phase(_spi, peripheral, ((~mode) & PHASE_MASK));

    device.peripheral = peripheral;

    return EXIT_SUCCESS;
}

uint8_t SpiDrv::transceive(Spi_Device_t &device, uint8_t misoBytes[],
                              uint8_t mosiBytes[], size_t numBytes) {
    assert(initialized);

    if (0 == numBytes || (NULL == misoBytes && NULL == mosiBytes)) {
        return EXIT_FAILURE;
    }

    enableChipSelect(device.peripheral);

    for (int i = 0; i < numBytes; i++) {
        WAIT_UNTIL(spi_is_tx_ready(_spi));

        if (NULL != mosiBytes) {
            spi_put(_spi, mosiBytes[i]);
        } else {
            spi_put(_spi, PLACEHOLDER);
        }

        if (NULL != misoBytes) {
            WAIT_UNTIL(spi_is_rx_ready(_spi));
            misoBytes[i] = spi_get(_spi);
        }
    }

    WAIT_UNTIL(spi_is_tx_empty(_spi));
    disableChipSelect(device.peripheral);
    spi_set_lastxfer(_spi);

    return EXIT_SUCCESS;
}

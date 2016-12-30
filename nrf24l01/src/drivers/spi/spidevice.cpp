#include <cassert>

#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/logging.hpp>

#include "spidevice.hpp"

#define POLARITY_MASK 0b00000010
#define PHASE_MASK 0b00000001
#define WAIT_UNTIL(x) while (!x)

static inline void setPinMode(ioport_pin_t pin, ioport_mode_t mode) {
    ioport_set_pin_mode(pin, mode);
    ioport_disable_pin(pin);
}

SpiDevice::SpiDevice(Spi *spi, uint32_t peripheral)
    : _spi(spi), _peripheral(peripheral) {}

SpiDevice::~SpiDevice() {
    spi_disable(_spi);
    spi_disable_clock(_spi);
}

void SpiDevice::init(uint32_t mode, uint32_t baudRate) {
    int16_t baudRateDiv = spi_calc_baudrate_div(baudRate, sysclk_get_cpu_hz());
    assert(baudRateDiv > 0);

    configurePeripheralChipSelectPin();

    spi_set_transfer_delay(_spi, _peripheral, 0, 0);
    spi_set_bits_per_transfer(_spi, _peripheral, SPI_CSR_BITS_8_BIT);
    spi_set_baudrate_div(_spi, _peripheral, baudRateDiv);
    spi_configure_cs_behavior(_spi, _peripheral, SPI_CS_KEEP_LOW);
    spi_set_clock_polarity(_spi, _peripheral, (mode & POLARITY_MASK) >> 1);
    spi_set_clock_phase(_spi, _peripheral, ((~mode) & PHASE_MASK));
}

uint8_t SpiDevice::transmit(uint8_t mosiBytes[], size_t mosiNumBytes,
                            ISpi_TransmitCallback_t callback, void *user) {
    size_t misoNumBytes = mosiNumBytes;
    uint8_t misoBytes[misoNumBytes];

    portENTER_CRITICAL();

    spi_set_peripheral_chip_select_value(_spi, ~(1 << _peripheral));

    for (int i = 0; i < mosiNumBytes; i++) {
        WAIT_UNTIL(spi_is_tx_ready(_spi));
        spi_put(_spi, mosiBytes[i]);

        WAIT_UNTIL(spi_is_rx_ready(_spi));
        misoBytes[i] = spi_get(_spi);
    }

    spi_set_lastxfer(_spi);

    spi_set_peripheral_chip_select_value(_spi, (1 << _peripheral));

    portEXIT_CRITICAL();

    if (callback) {
        callback(misoBytes, misoNumBytes, user);
    }

    return (0);
}

void SpiDevice::configurePeripheralChipSelectPin() {
    if (_spi == SPI0) {
        switch (_peripheral) {
            case 0: setPinMode(SPI0_NPCS0_GPIO, SPI0_NPCS0_FLAGS); break;
            case 1: setPinMode(SPI0_NPCS1_GPIO, SPI0_NPCS1_FLAGS); break;
            case 2: setPinMode(SPI0_NPCS2_GPIO, SPI0_NPCS2_FLAGS); break;
            case 3: setPinMode(SPI0_NPCS3_GPIO, SPI0_NPCS3_FLAGS); break;
        }
    }
}

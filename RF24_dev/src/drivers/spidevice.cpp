#include <cassert>

#include <asf.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <xXx/utils/logging.hpp>

#include "spidevice.hpp"

namespace drivers {

#define POLARITY_MASK (0b00000010)
#define PHASE_MASK (0b00000001)
#define WAIT_UNTIL(x) while (!x)

static SemaphoreHandle_t semaphore;
static bool masterModeInitialized = false;

static void setPinMode(ioport_pin_t pin, ioport_mode_t mode) {
    ioport_set_pin_mode(pin, mode);
    ioport_disable_pin(pin);
}

SpiDevice::SpiDevice(Spi *spi, uint32_t peripheral) : _spi(spi), _peripheral(peripheral) {
    vSemaphoreCreateBinary(semaphore);
    assert(semaphore != NULL);
}

SpiDevice::~SpiDevice() {
    spi_disable(_spi);
    spi_disable_clock(_spi);
    // TODO: Disable master mode
}

void SpiDevice::init(uint32_t mode, uint32_t baudRate) {
    int16_t baudRateDiv = spi_calc_baudrate_div(baudRate, sysclk_get_cpu_hz());
    assert(baudRateDiv > 0);

    enableSpiMasterMode();
    configurePeripheralChipSelectPin();

    spi_set_transfer_delay(_spi, _peripheral, 0, 0);
    spi_set_bits_per_transfer(_spi, _peripheral, SPI_CSR_BITS_8_BIT);
    spi_set_baudrate_div(_spi, _peripheral, baudRateDiv);
    spi_configure_cs_behavior(_spi, _peripheral, SPI_CS_KEEP_LOW);
    spi_set_clock_polarity(_spi, _peripheral, (mode & POLARITY_MASK) >> 1);
    spi_set_clock_phase(_spi, _peripheral, ((~mode) & PHASE_MASK));
}

uint8_t SpiDevice::transmit_receive(uint8_t txBytes[], uint8_t rxBytes[], size_t numBytes) {
    xSemaphoreTake(semaphore, portMAX_DELAY);
    taskENTER_CRITICAL();
    enableChipSelect();

    for (size_t i = 0; i < numBytes; i++) {
        WAIT_UNTIL(spi_is_tx_ready(_spi));
        spi_put(_spi, txBytes[i]);

        WAIT_UNTIL(spi_is_rx_ready(_spi));
        rxBytes[i] = spi_get(_spi);
    }

    spi_set_lastxfer(_spi);
    disableChipSelect();
    taskEXIT_CRITICAL();
    xSemaphoreGive(semaphore);

    return (0);
}

void SpiDevice::enableChipSelect() {
    spi_set_peripheral_chip_select_value(_spi, ~(1 << _peripheral));
}

void SpiDevice::disableChipSelect() {
    spi_set_peripheral_chip_select_value(_spi, (1 << _peripheral));
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

void SpiDevice::configureSpiPins() {
    if (_spi == SPI0) {
        setPinMode(SPI0_MISO_GPIO, SPI0_MISO_FLAGS);
        setPinMode(SPI0_MOSI_GPIO, SPI0_MOSI_FLAGS);
        setPinMode(SPI0_SPCK_GPIO, SPI0_SPCK_FLAGS);
    }
}

void SpiDevice::enableSpiMasterMode(uint32_t delayBetweenChipSelect) {
    if (masterModeInitialized) return;

    configureSpiPins();

    spi_enable_clock(_spi);
    spi_reset(_spi);
    spi_set_master_mode(_spi);
    spi_disable_mode_fault_detect(_spi);
    spi_disable_loopback(_spi);
    spi_set_fixed_peripheral_select(_spi);
    spi_disable_peripheral_select_decode(_spi);
    spi_set_delay_between_chip_select(_spi, delayBetweenChipSelect);
    spi_enable(_spi);
}

} /* namespace */

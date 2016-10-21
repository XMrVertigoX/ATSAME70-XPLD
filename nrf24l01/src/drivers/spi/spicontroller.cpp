#include <asf.h>

#include "spicontroller.hpp"

static inline void setPinMode(ioport_pin_t pin, ioport_mode_t mode) {
    ioport_set_pin_mode(pin, mode);
    ioport_disable_pin(pin);
}

void SpiController::enableMasterMode(Spi *spi,
                                     uint32_t delayBetweenChipSelect) {
    configurePins(spi);

    spi_enable_clock(spi);
    spi_reset(spi);
    spi_set_master_mode(spi);
    spi_disable_mode_fault_detect(spi);
    spi_disable_loopback(spi);
    spi_set_fixed_peripheral_select(spi);
    spi_disable_peripheral_select_decode(spi);
    spi_set_delay_between_chip_select(spi, delayBetweenChipSelect);
    spi_enable(spi);
}

void SpiController::configurePins(Spi *spi) {
    if (spi == SPI0) {
        setPinMode(SPI0_MISO_GPIO, SPI0_MISO_FLAGS);
        setPinMode(SPI0_MOSI_GPIO, SPI0_MOSI_FLAGS);
        setPinMode(SPI0_SPCK_GPIO, SPI0_SPCK_FLAGS);
    }
}

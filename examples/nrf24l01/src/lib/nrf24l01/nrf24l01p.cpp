#include "spidrv.hpp"

#include "nrf24l01p.hpp"
#include "nrf24l01p_definitions.h"

#define CONFIG_REGISTER_MASK 0b00011111
#define PLACEHOLDER 0xFF

nRF24L01P::nRF24L01P(SpiDrv &spi, SpiDrv_Device_t &device)
    : _spi(spi), _device(device) {}

nRF24L01P::~nRF24L01P() {}

uint8_t nRF24L01P::readRegister(uint8_t reg, uint8_t &buf) {
    uint8_t miso[2];
    uint8_t mosi[2];

    mosi[0] = R_REGISTER | (reg & CONFIG_REGISTER_MASK);
    mosi[1] = PLACEHOLDER;

    _spi.transceive(_device, miso, mosi, sizeof(mosi));

    buf = miso[1];

    return miso[0];
}

uint8_t nRF24L01P::writeRegister(uint8_t reg, uint8_t val) {
    uint8_t miso[2];
    uint8_t mosi[2];

    mosi[0] = W_REGISTER | (reg & CONFIG_REGISTER_MASK);
    mosi[1] = val;

    _spi.transceive(_device, miso, mosi, sizeof(mosi));

    return miso[0];
}

void nRF24L01P::powerDown() {}

void nRF24L01P::powerUp() {}

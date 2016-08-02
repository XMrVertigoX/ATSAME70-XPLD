#include <string.h>

#include "logging.hpp"
#include "spidrv.hpp"

#include "nrf24l01p.hpp"
#include "nrf24l01p_definitions.h"

#define COMMAND_REGISTER_MASK 0b00011111
#define PLACEHOLDER 0xFF

nRF24L01P::nRF24L01P(SpiDrv &spi, SpiDrv_Device_t &device)
        : _spi(spi),
          _device(device),
          _status(0) {
}

nRF24L01P::~nRF24L01P() {
}

uint8_t nRF24L01P::read(uint8_t addr, uint8_t bytes[], uint32_t numBytes) {
    uint8_t miso[numBytes + 1];
    uint8_t mosi[numBytes + 1];

    mosi[0] = R_REGISTER | (addr & COMMAND_REGISTER_MASK);
    memset(&mosi[1], PLACEHOLDER, numBytes);

    _spi.transceive(_device, miso, mosi, numBytes + 1);

    updateStatus(miso[0]);
    memcpy(&miso[1], bytes, numBytes);

    return 0;
}

uint8_t nRF24L01P::write(uint8_t command, uint8_t bytes[], uint32_t numBytes) {
    uint8_t miso[numBytes + 1];
    uint8_t mosi[numBytes + 1];

    mosi[0] = W_REGISTER | (command & COMMAND_REGISTER_MASK);
    memcpy(&mosi[1], bytes, numBytes);

    _spi.transceive(_device, miso, mosi, sizeof(mosi));

    updateStatus(miso[0]);

    return 0;
}

void nRF24L01P::updateStatus(uint8_t status) {
    _status = status;
}

void nRF24L01P::powerDown() {
    LOG("powerDown");

    uint8_t buffer[1];
    read(CONFIG, buffer, sizeof(buffer));

    buffer[0] &= ~PWR_UP;
    write(CONFIG, buffer, sizeof(buffer));
}

void nRF24L01P::powerUp() {
    LOG("powerUp");

    uint8_t buffer[1];
    read(CONFIG, buffer, sizeof(buffer));

    buffer[0] |= PWR_UP;
    write(CONFIG, buffer, sizeof(buffer));
}

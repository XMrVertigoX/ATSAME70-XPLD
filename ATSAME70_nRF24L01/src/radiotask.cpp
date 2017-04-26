#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace xXx;

const uint32_t base  = 0xE7E7E7E7;
const uint8_t prefix = 0xE7;
const int8_t channel = 2;

RadioTask::RadioTask(nRF24L01P_ESB &receiver) : _receiver(receiver), _led(Gpio(LED_0_PIN)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    _receiver.setRxBaseAddress_0(base);
    _receiver.setRxAddressPrefix(0, prefix);

    _receiver.setDataRate(DataRate_2MBPS);
    _receiver.setCrcConfig(CrcConfig_2Bytes);
    _receiver.setChannel(channel);
    _receiver.switchOperatingMode(OperatingMode_Rx);

    _led.init(IOPORT_DIR_OUTPUT);
}

void RadioTask::loop() {}

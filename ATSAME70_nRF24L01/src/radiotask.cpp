#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace xXx;

const uint32_t baseAddress  = 0xE7E7E7E7;
const uint8_t address = 0xE7;
const int8_t channel = 2;

RadioTask::RadioTask(nRF24L01P_ESB& receiver)
    : _receiver(receiver), _led(Gpio(LED_0_PIN)), _rxQueue(Queue<RF24_Package_t>(3)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    _receiver.setRxBaseAddress_0(baseAddress);
    _receiver.setRxAddress(0, address);

    _receiver.setDataRate(RF24_DataRate_2MBPS);
    _receiver.setCrcConfig(RF24_CrcConfig_2Bytes);
    _receiver.setChannel(channel);
    _receiver.switchOperatingMode(RF24_OperatingMode_Rx);

    _receiver.startListening(0, &_rxQueue);

    _led.init(IOPORT_DIR_OUTPUT);
}

void RadioTask::loop() {
    RF24_Package_t package;
    _rxQueue.dequeue(package);
    BUFFER("package:", package.bytes, package.numBytes);
    _led.toggle();
}

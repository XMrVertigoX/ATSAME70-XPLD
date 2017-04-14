#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace xXx;

const int64_t address = 0xE7E7E7E7E7;
const int8_t channel  = 2;

RadioTask::RadioTask(nRF24L01P_ESB &receiver)
    : _receiver(receiver), _queue(Queue<Package_t>(10)), _led(Gpio(LED_0_PIN)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    _receiver.configureRxPipe(0, _queue, address);
    _receiver.setDataRate(DataRate_2MBPS);
    _receiver.setCrcConfig(CrcConfig_2Bytes);
    _receiver.setChannel(channel);
    _receiver.switchOperatingMode(OperatingMode_Rx);

    _led.init(IOPORT_DIR_OUTPUT);
}

void RadioTask::loop() {
    Package_t rxPackage;
    _queue.dequeue(rxPackage);
    _led.toggle();

    BUFFER("rxPackage", rxPackage.bytes, rxPackage.numBytes);
}

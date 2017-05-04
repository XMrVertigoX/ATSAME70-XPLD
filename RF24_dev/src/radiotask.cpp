#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace xXx;

static const RF24_Address_t address_0 = 0xE7E7E7E7E7;

static const int8_t channel = 2;

RadioTask::RadioTask(RF24_ESB& receiver)
    : receiver(receiver), led(Gpio(LED_0_PIN)), rxQueue(Queue<RF24_Package_t>(3)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    RF24_Status status = RF24_Status::Success;

    led.init(IOPORT_DIR_OUTPUT);

    status = receiver.setRxAddress(0, address_0);
    status = receiver.setDataRate(RF24_DataRate::DR_2MBPS);
    status = receiver.setCrcConfig(RF24_CRCConfig::CRC_2Bytes);
    status = receiver.setChannel(channel);
    status = receiver.enableRxDataPipe(0, rxQueue);

    assert(status == RF24_Status::Success);

    receiver.enterRxMode();

    sleep(100);
}

void RadioTask::loop() {
    RF24_Package_t package;
    rxQueue.dequeue(package);
    BUFFER("package:", package.bytes, package.numBytes);
    led.toggle();
}

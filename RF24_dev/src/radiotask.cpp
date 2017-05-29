#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/rf24/rf24.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace xXx;

static const RF24_Address_t address_p0 = 0xE7E7E7E7E7;
static const RF24_Address_t address_p1 = 0xC2C2C2C2C2;
static const RF24_Channel_t channel = 2;

RadioTask::RadioTask(RF24& receiver)
    : receiver(receiver), led(Gpio(LED_0_PIN)), rxQueue(Queue<RF24_DataPackage_t>(3)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    RF24_Status status = RF24_Status::Success;

    led.init(IOPORT_DIR_OUTPUT);

    receiver.setup();

    status = receiver.setRxAddress(0, address_p1);
    status = receiver.setRxAddress(1, address_p0);
    status = receiver.setDataRate(RF24_DataRate::DR_2MBPS);
    status = receiver.setCrcConfig(RF24_CRCConfig::CRC_2Bytes);
    status = receiver.setChannel(channel);
    status = receiver.configureRxDataPipe(1, &rxQueue);

    assert(status == RF24_Status::Success);

    receiver.enterRxMode();

    sleep(100);
}

void RadioTask::loop() {
    RF24_DataPackage_t package;

    if (rxQueue.queueMessagesWaiting()) {
        rxQueue.dequeue(package, 0);
        BUFFER("package:", package.bytes, package.numBytes);
        led.toggle();
    }

    receiver.loop();
}

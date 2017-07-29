#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/rf24/rf24.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace drivers;

static const uint32_t baseAddress_0 = 0xE7E7E7E7;
static const uint32_t baseAddress_1 = 0xC2C2C2C2;

static const uint8_t address_p0 = 0xE7;
static const uint8_t address_p1 = 0xC2;
// static const uint8_t address_p2 = 0xC3;
// static const uint8_t address_p3 = 0xC4;
// static const uint8_t address_p4 = 0xC5;
// static const uint8_t address_p5 = 0xC6;

static const uint8_t channel = 2;

RadioTask::RadioTask(xXx::RF24 &receiver)
    : receiver(receiver), led(Gpio(LED_0_PIN)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    RF24_Status status = RF24_Status::Success;

    RF24_RxCallback_t callback = [](RF24_DataPackage_t data, void *user) {
        RadioTask *self = static_cast<RadioTask *>(user);
        HEXDUMP(data.bytes, data.numBytes);
        self->led.toggle();
    };

    led.init(IOPORT_DIR_OUTPUT);

    receiver.setup();

    status = receiver.writeRxBaseAddress(0, baseAddress_0);
    assert(status == RF24_Status::Success);

    status = receiver.writeRxBaseAddress(1, baseAddress_1);
    assert(status == RF24_Status::Success);

    status = receiver.writeRxAddress(0, address_p0);
    assert(status == RF24_Status::Success);

    status = receiver.writeRxAddress(1, address_p1);
    assert(status == RF24_Status::Success);

    status = receiver.setChannel(channel);
    assert(status == RF24_Status::Success);

    status = receiver.setCrcConfig(RF24_CRCConfig::CRC_2Bytes);
    assert(status == RF24_Status::Success);

    status = receiver.setDataRate(RF24_DataRate::DR_2MBPS);
    assert(status == RF24_Status::Success);

    status = receiver.startListening(0, callback, this);
    assert(status == RF24_Status::Success);

    receiver.enterRxMode();

    sleep(100);
}

void RadioTask::loop() {
    receiver.loop();
}

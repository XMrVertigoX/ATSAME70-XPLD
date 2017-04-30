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
static const RF24_Address_t address_1 = 0xC2C2C2C2C2;
static const RF24_Address_t address_2 = 0xC2C2C2C2C3;
static const RF24_Address_t address_3 = 0xC2C2C2C2C4;
static const RF24_Address_t address_4 = 0xC2C2C2C2C5;
static const RF24_Address_t address_5 = 0xC2C2C2C2C6;

static const int8_t channel = 2;

RadioTask::RadioTask(RF24_ESB& receiver)
    : _receiver(receiver), _led(Gpio(LED_0_PIN)), _rxQueue(Queue<RF24_Package_t>(3)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    RF24_Status_t status = RF24_Status_Success;

    _led.init(IOPORT_DIR_OUTPUT);

    status = _receiver.setRxAddress(0, address_0);
    status = _receiver.setRxAddress(1, address_1);
    status = _receiver.setRxAddress(2, address_2);
    status = _receiver.setRxAddress(3, address_3);
    status = _receiver.setRxAddress(4, address_4);
    status = _receiver.setRxAddress(5, address_5);
    status = _receiver.setDataRate(RF24_DataRate::DR_2MBPS);
    status = _receiver.setCrcConfig(RF24_CRCConfig::CRC_2Bytes);
    status = _receiver.setChannel(channel);
    status = _receiver.enableRxDataPipe(0, _rxQueue);

    _receiver.enterRxMode();

    assert(status == RF24_Status_Success);
}

void RadioTask::loop() {
    RF24_Package_t package;
    _rxQueue.dequeue(package);
    BUFFER("package:", package.bytes, package.numBytes);
    _led.toggle();
}

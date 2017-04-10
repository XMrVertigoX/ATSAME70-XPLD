#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/os/simpletask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

using namespace xXx;

static const int64_t address = 0xE7E7E7E7E7;

RadioTask::RadioTask(nRF24L01P_ESB &receiver) : _receiver(receiver), _queue(Queue<uint8_t>(256)) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    _receiver.configureRxPipe(0, _queue, address);
    _receiver.setDataRate(DataRate_2MBPS);
    _receiver.setCrcConfig(CrcConfig_2Bytes);
    _receiver.setChannel(2);
    _receiver.switchOperatingMode(OperatingMode_Rx);
}

void RadioTask::loop() {
    uint8_t tmp;
    _queue.dequeue(tmp);

    LOG("%d", tmp);
}

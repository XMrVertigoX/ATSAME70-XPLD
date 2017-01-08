#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nRF24L01/nRF24L01.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

RadioTask::RadioTask(nRF24L01 &rf24) : ArduinoTask(1024, 1), _rf24(rf24) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    vTaskDelay(100 / portTICK_PERIOD_MS);

    _rf24.init();
    _rf24.openReadingPipe(0, 0xF0F0F0F0F0);
}

void RadioTask::loop() {
    //    _rf24.startListening();
}

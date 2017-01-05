#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/RF24/nRF24L01.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

RadioTask::RadioTask(nRF24L01 &rf24) : ArduinoTask(1024, 1), _rf24(rf24) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    uint8_t buffer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    _rf24.begin();

    vTaskDelay(1 / portTICK_PERIOD_MS);

    LOG("%d", _rf24.getPALevel());
    _rf24.setPALevel(RF24_PA_18dBm);
    LOG("%d", _rf24.getPALevel());
    _rf24.openWritingPipe(0);
    _rf24.write(buffer, sizeof(buffer));
}

void RadioTask::loop() {
    // vTaskDelay(500 / portTICK_PERIOD_MS);
}

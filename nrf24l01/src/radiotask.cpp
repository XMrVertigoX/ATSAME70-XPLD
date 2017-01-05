#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/RF24/RF24.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include "radiotask.hpp"

RadioTask::RadioTask(RF24 &rf24) : ArduinoTask(256, 1), _rf24(rf24) {}

RadioTask::~RadioTask() {}

void RadioTask::setup() {
    uint8_t buffer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    _rf24.begin();
    _rf24.openWritingPipe(0x0f0f0f0f0f);
    _rf24.write(buffer, sizeof(buffer));
}

void RadioTask::loop() {
    // vTaskDelay(500 / portTICK_PERIOD_MS);
}

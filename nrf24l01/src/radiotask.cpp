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
    vTaskDelay(100 / portTICK_PERIOD_MS);

    uint8_t buffer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    _rf24.init();

    _rf24.openWritingPipe(0xE0E1E2E3E4);
    //    _rf24.openReadingPipe(1, 0xE0E1E2E3E4);

    _rf24.write(buffer, sizeof(buffer));
}

void RadioTask::loop() {
    // vTaskDelay(500 / portTICK_PERIOD_MS);
}

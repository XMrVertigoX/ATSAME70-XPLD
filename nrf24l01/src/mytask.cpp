#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/RF24/RF24.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/gpio/gpio.hpp>
#include <drivers/spi/spicontroller.hpp>
#include <drivers/spi/spidevice.hpp>

#include "mytask.hpp"

MyTask::MyTask(RF24 &rf24) : ArduinoTask(256, 1), _rf24(rf24) {}

MyTask::~MyTask() {}

void MyTask::setup() {
    uint8_t buffer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    _rf24.begin();
    _rf24.openWritingPipe(0x0f0f0f0f0f);
    _rf24.write(buffer, sizeof(buffer));
}

void MyTask::loop() {
    // vTaskDelay(500 / portTICK_PERIOD_MS);
}

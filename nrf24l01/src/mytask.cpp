#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/spi/spicontroller.hpp>
#include <drivers/spi/spidevice.hpp>

#include "mytask.hpp"

MyTask::MyTask() : ArduinoTask(256, 1) {}

MyTask::~MyTask() {}

void MyTask::setup() {
    SpiDevice spi(SPI0, 1, 0, 10000000);
    nRF24L01P transmitter(spi);

    vTaskDelay(100 / portTICK_PERIOD_MS);
    transmitter.config_powerUp();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    transmitter.config_powerDown();
}

void MyTask::loop() {
    LOG("LED");
    LED_Toggle(LED0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/gpio/gpio.hpp>
#include <drivers/spi/spicontroller.hpp>
#include <drivers/spi/spidevice.hpp>

#include "mytask.hpp"

MyTask::MyTask(SpiDevice &spi, Gpio &ce, Gpio &irq)
    : ArduinoTask(256, 1), _spi(spi), _ce(ce), _irq(irq) {}

MyTask::~MyTask() {}

void MyTask::setup() {
    //    nRF24L01P transmitter(_spi, _irq, _ce);

    //    vTaskDelay(100 / portTICK_PERIOD_MS);
    //    transmitter.config_powerUp();
    //    vTaskDelay(100 / portTICK_PERIOD_MS);
    //    transmitter.config_powerDown();
}

void MyTask::loop() {
    // vTaskDelay(500 / portTICK_PERIOD_MS);
}

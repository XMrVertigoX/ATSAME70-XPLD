#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/spi/spicontroller.hpp>
#include <drivers/spi/spidevice.hpp>

#include "mytask.hpp"

void MyTask::setup() {
    SpiDevice spi(SPI0, 1, 0, 10000000);
    nRF24L01P transmitter(spi);

    vTaskDelay(100 / portTICK_PERIOD_MS);

    transmitter.config_powerUp();

    vTaskDelay(100 / portTICK_PERIOD_MS);

    transmitter.config_powerDown();
}

void MyTask::loop() {}

#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include "lib/driver/spidrv.hpp"
#include "lib/nrf24l01/nrf24l01p.hpp"
#include "lib/nrf24l01/nrf24l01p_definitions.h"

#include "mytask.hpp"

MyTask::MyTask(SpiDrv spi) : _spi(spi) {}

MyTask::~MyTask() {}

void MyTask::setup() {
    _spi.setupDevice(_spiDevice, SpiDrv_Peripheral_3, SpiDrv_Mode_0, 2000000);

    nRF24L01P transmitter(_spi, _spiDevice);

    vTaskDelay(100 / portTICK_PERIOD_MS);

    transmitter.config_powerUp();
    transmitter.config_powerDown();
}

void MyTask::loop() {}

#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "lib/driver/spidrv.hpp"
#include "lib/nrf24l01/nrf24l01p.hpp"
#include "lib/nrf24l01/nrf24l01p_definitions.h"
#include "lib/util/logging.hpp"

SpiDrv spi(SPI0);
SpiDrv_Device_t nrf24l01;

void simpleTask(void *user) {
    nRF24L01P transmitter(spi, nrf24l01);

    vTaskDelay(100 / portTICK_PERIOD_MS);

    transmitter.config_powerUp();
    transmitter.config_powerDown();

    LOG("enter loop");
    for (;;) {
    }
}

int main() {
    sysclk_init();
    board_init();

    spi.enableMasterMode();
    spi.setupDevice(nrf24l01, SpiDrv_Peripheral_3, SpiDrv_Mode_0, 2000000);

    // IRQ
    ioport_enable_pin(PIO_PA6_IDX);
    ioport_set_pin_dir(PIO_PA6_IDX, IOPORT_DIR_INPUT);

    // CE
    ioport_enable_pin(PIO_PD11_IDX);
    ioport_set_pin_dir(PIO_PD11_IDX, IOPORT_DIR_OUTPUT);

    xTaskCreate(simpleTask, NULL, 256, NULL, 1, NULL);

    LOG("enter scheduler");
    vTaskStartScheduler();

    return (EXIT_FAILURE);
}

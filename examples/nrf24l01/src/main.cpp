#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"
#include "spimaster.hpp"

SpiMaster spiMaster(SPI0);
Spi_Device_t nrf24l01;

uint8_t pwr_up[] = {0x00, 0b0000010};
uint8_t status[2];

void task(void *user) {
    vTaskDelay(100 / portTICK_PERIOD_MS);

    spiMaster.transceive(nrf24l01, status, pwr_up, sizeof(pwr_up));

    for (;;) {
        spiMaster.transceive(nrf24l01, status, NULL, sizeof(status));
    }
}

int main() {
    sysclk_init();
    board_init();

    spiMaster.initialize();
    spiMaster.setupDevice(nrf24l01, Spi_Peripheral_3, Spi_Mode_0, 10000000);

    // IRQ
    ioport_enable_pin(PIO_PA6_IDX);
    ioport_set_pin_dir(PIO_PA6_IDX, IOPORT_DIR_INPUT);

    // CE
    ioport_enable_pin(PIO_PD11_IDX);
    ioport_set_pin_dir(PIO_PD11_IDX, IOPORT_DIR_OUTPUT);

    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    LOG("Enter scheduler");

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

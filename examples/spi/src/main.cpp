#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"
#include "spimaster.hpp"

#define SPI_FREQ 10000000

SpiMaster spiMaster(SPI0);
Spi_Device_t logicAnalyzer;

uint8_t foo[] = { 0x0B, 0x07 };
uint8_t bar[] = { 0x00, 0x00 };

void task(void *user) {
    for (;;) {
        spiMaster.transceive(logicAnalyzer, bar, foo, sizeof(bar));
    }
}

int main() {
    sysclk_init();
    board_init();

    spiMaster.initialize();
    spiMaster.setupDevice(logicAnalyzer, Spi_Peripheral_1, Spi_Mode_0, SPI_FREQ);

    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    LOG("Enter scheduler");

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

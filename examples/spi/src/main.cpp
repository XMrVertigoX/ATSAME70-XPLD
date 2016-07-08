#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"
#include "spimaster.hpp"

SpiMaster spi(SPI0);
Spi_Device_t mySpiDevice;

uint8_t foo[] = { 0x0B, 0x07 };
uint8_t bar[] = { 0x00, 0x00 };

void task(void *user) {
    spi.transceive(mySpiDevice, foo, bar, sizeof(bar));

    for (;;) {
        spi.transceive(mySpiDevice, bar, NULL, sizeof(bar));
    }
}

int main() {
    sysclk_init();
    board_init();

    spi.initialize();
    spi.setupDevice(mySpiDevice, spiPeripheral1, spiMode0, 10000000);

    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

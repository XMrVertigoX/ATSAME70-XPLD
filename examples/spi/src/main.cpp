#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

struct spi_device device;

uint8_t txData[] = "Test";
uint8_t rxData[sizeof(txData)];

void task(void *user) {
    for (;;) {
        ioport_set_pin_level(SPI0_NPCS1_GPIO, IOPORT_PIN_LEVEL_LOW);

        spi_select_device(SPI0, &device);
        spi_write_packet(SPI0, txData, sizeof(txData));
        spi_read_packet(SPI0, rxData, sizeof(txData));
        spi_deselect_device(SPI0, &device);

        ioport_set_pin_level(SPI0_NPCS1_GPIO, IOPORT_PIN_LEVEL_HIGH);

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

int main() {
    sysclk_init();
    board_init();

    ioport_set_pin_dir(SPI0_NPCS1_GPIO, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(SPI0_NPCS1_GPIO, IOPORT_PIN_LEVEL_HIGH);

    device.id = ioport_pin_to_port_id(SPI0_NPCS1_GPIO);

    spi_master_init(SPI0);
    spi_master_setup_device(SPI0, &device, SPI_MODE_0, 1000000, 0);
    spi_enable(SPI0);

    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

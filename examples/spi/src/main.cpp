#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

struct spi_device device = { 0 };

void task(void *user) {
    for (;;) {
    }
}

int main() {
    sysclk_init();
    board_init();
    ioport_init();

    spi_master_init(SPI0);
    spi_master_setup_device(SPI0, &device, SPI_MODE_0, 100000, 0);
    spi_enable(SPI0);

//    ioport_set_pin_dir(SPI0_MISO_GPIO, IOPORT_DIR_INPUT);
//    ioport_set_pin_dir(SPI0_MOSI_GPIO, IOPORT_DIR_OUTPUT);
//    ioport_set_pin_dir(SPI0_SPCK_GPIO, IOPORT_DIR_OUTPUT);
    ioport_set_pin_dir(SPI0_NPCS1_GPIO, IOPORT_DIR_OUTPUT);

    uint8_t dataOut[] = "Test";
    uint8_t dataIn[sizeof(dataOut)];

    ioport_set_pin_level(PIO_PD25_IDX, IOPORT_PIN_LEVEL_LOW);

    spi_select_device(SPI0, &device);
    spi_write_packet(SPI0, dataOut, sizeof(dataOut));
    spi_read_packet(SPI0, dataIn, sizeof(dataOut));
    spi_deselect_device(SPI0, &device);

    ioport_set_pin_level(PIO_PD25_IDX, IOPORT_PIN_LEVEL_HIGH);

//    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

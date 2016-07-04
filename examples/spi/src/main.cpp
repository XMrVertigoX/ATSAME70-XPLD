#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

#define waitForTx(x) while (!spi_is_tx_empty(x))

struct spi_device spiDevice0 = {0};

uint8_t foo[] = {0x0B, 0x07};
uint8_t bar[] = {0x09, 0x00};

void task(void *user) {
    spi_select_device(SPI0, &spiDevice0);

    ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_LOW);
    spi_write_packet(SPI0, foo, 2);
    waitForTx(SPI0);
    ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_HIGH);

    ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_LOW);
    spi_write_packet(SPI0, bar, 2);
    waitForTx(SPI0);
    ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_HIGH);

    spi_deselect_device(SPI0, &spiDevice0);

    for (;;) {
        // ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_LOW);
        //
        // spi_select_device(SPI0, &spiDevice0);
        // spi_write_packet(SPI0, shutdownMode, 2);
        // spi_deselect_device(SPI0, &spiDevice0);
        //
        // ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_HIGH);
        //
        // vTaskDelay(200 / portTICK_PERIOD_MS);
        //
        // ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_LOW);
        //
        // spi_select_device(SPI0, &spiDevice0);
        // spi_write_packet(SPI0, normalOperation, 2);
        // spi_deselect_device(SPI0, &spiDevice0);
        //
        // ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_HIGH);
        //
        // vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}

int main() {
    sysclk_init();
    board_init();

    ioport_set_pin_dir(PIO_PD25_IDX, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(PIO_PD25_IDX, IOPORT_PIN_LEVEL_HIGH);

    ioport_set_pin_dir(PIO_PD27_IDX, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(PIO_PD27_IDX, IOPORT_PIN_LEVEL_HIGH);

    spi_master_init(SPI0);
    spi_master_setup_device(SPI0, &spiDevice0, SPI_MODE_0, 10000000, 0);
    spi_enable(SPI0);

    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <lib/services/spidrv.hpp>
#include <lib/util/iarduino.hpp>
#include <lib/util/logging.hpp>

#include "mytask.hpp"

#define ARDUINO                                       \
    [](void *pvParameters) {                          \
        IArduino *arduino = (IArduino *)pvParameters; \
        arduino->setup();                             \
        for (;;) arduino->loop();                     \
    }

SpiDrv spi(SPI0);
MyTask myTask(spi);

int main() {
    sysclk_init();
    board_init();

    spi.enableMasterMode();

    // IRQ
    ioport_enable_pin(PIO_PA6_IDX);
    ioport_set_pin_dir(PIO_PA6_IDX, IOPORT_DIR_INPUT);

    // CE
    ioport_enable_pin(PIO_PD11_IDX);
    ioport_set_pin_dir(PIO_PD11_IDX, IOPORT_DIR_OUTPUT);

    xTaskCreate(ARDUINO, "nRF24L01P", 256, &myTask, 1, NULL);

    vTaskStartScheduler();
}

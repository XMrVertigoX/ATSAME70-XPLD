#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <services/spidrv.hpp>
#include <util/iarduinotask.hpp>
#include <util/logging.hpp>

#include "mytask.hpp"

SpiDrv spi(SPI0);
MyTask myTask(spi);

static void arduinoTaskFunction(void *pvParameters) {
    IArduinoTask *arduino = static_cast<IArduinoTask *>(pvParameters);
    arduino->setup();
    for (;;) arduino->loop();
}

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

    xTaskCreate(arduinoTaskFunction, "nRF24L01P", 256, &myTask, 1, NULL);

    vTaskStartScheduler();
}

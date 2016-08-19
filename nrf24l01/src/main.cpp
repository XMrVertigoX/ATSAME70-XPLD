#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/services/spidrv.hpp>
#include <xXx/util/arduinotask.hpp>
#include <xXx/util/logging.hpp>

#include "mytask.hpp"

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

    myTask.attachToScheduler("DEFAULT", 256, 1);

    vTaskStartScheduler();
}

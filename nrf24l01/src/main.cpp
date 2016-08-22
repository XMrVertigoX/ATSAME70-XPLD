#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/util/arduinotask.hpp>
#include <xXx/util/logging.hpp>

#include "driver/spicontroller.hpp"
#include "mytask.hpp"

int main() {
    sysclk_init();
    board_init();

    SpiController::getInstance().enableMaster(SPI0);

    // IRQ
    ioport_enable_pin(PIO_PA6_IDX);
    ioport_set_pin_dir(PIO_PA6_IDX, IOPORT_DIR_INPUT);

    // CE
    ioport_enable_pin(PIO_PD11_IDX);
    ioport_set_pin_dir(PIO_PD11_IDX, IOPORT_DIR_OUTPUT);

    MyTask::getInstance().attachToScheduler(256, 1);

    vTaskStartScheduler();
}

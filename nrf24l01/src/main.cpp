#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/spi/spicontroller.hpp>

#include "mytask.hpp"

int main() {
    sysclk_init();
    board_init();

    sysclk_enable_peripheral_clock(ID_XDMAC);

    // IRQ
    ioport_enable_pin(PIO_PA6_IDX);
    ioport_set_pin_dir(PIO_PA6_IDX, IOPORT_DIR_INPUT);

    // CE
    ioport_enable_pin(PIO_PD11_IDX);
    ioport_set_pin_dir(PIO_PD11_IDX, IOPORT_DIR_OUTPUT);

    SpiController::getInstance().enableMasterMode(SPI0);

    MyTask::getInstance().attachToScheduler(256, 1);

    vTaskStartScheduler();
}

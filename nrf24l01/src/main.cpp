#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/spi/spicontroller.hpp>
#include <sleepmanager.hpp>

#include "mytask.hpp"

int main() {
    sysclk_init();

    SCB_EnableICache();
    SCB_EnableDCache();

    board_init();

    sysclk_enable_peripheral_clock(ID_XDMAC);

    // IRQ
    ioport_enable_pin(PIO_PA6_IDX);
    ioport_set_pin_dir(PIO_PA6_IDX, IOPORT_DIR_INPUT);

    // CE
    ioport_enable_pin(PIO_PD11_IDX);
    ioport_set_pin_dir(PIO_PD11_IDX, IOPORT_DIR_OUTPUT);

    SleepManager::getInstance().init();
    SpiController::getInstance().enableMasterMode(SPI0);
    MyTask::getInstance().attach(256, 1);

    sleepmgr_lock_mode(SLEEPMGR_SLEEP_WFE);

    vTaskStartScheduler();
}

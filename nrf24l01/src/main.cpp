#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/os/arduinotask.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/gpio/gpio.hpp>
#include <drivers/spi/spicontroller.hpp>
#include <drivers/spi/spidevice.hpp>
#include <sleepmanager.hpp>

#include "mytask.hpp"

SleepManager &sleepManager   = SleepManager::getInstance();
SpiController &spiController = SpiController::getInstance();

SpiDevice spi(SPI0, 1);
Gpio ce;
Gpio irq;

MyTask myTask(spi, ce, irq);

int main() {
    sysclk_init();

    SCB_EnableICache();
    SCB_EnableDCache();

    board_init();

    //    sysclk_enable_peripheral_clock(ID_XDMAC);

    // IRQ
    //    ioport_enable_pin(EXT1_PIN_9);
    //    ioport_set_pin_dir(EXT1_PIN_9, IOPORT_DIR_INPUT);

    // CE
    //    ioport_enable_pin(EXT1_PIN_10);
    //    ioport_set_pin_dir(EXT1_PIN_10, IOPORT_DIR_OUTPUT);

    sleepManager.init();
    spiController.enableMasterMode(SPI0);
    spi.init(0, 10000000);

    vTaskStartScheduler();
}

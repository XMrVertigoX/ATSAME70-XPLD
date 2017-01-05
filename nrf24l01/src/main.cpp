#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/RF24/RF24.hpp>
#include <xXx/os/arduinotask.hpp>
#include <xXx/templates/queue.hpp>
#include <xXx/utils/logging.hpp>

#include <drivers/gpio/gpio.hpp>
#include <drivers/spi/spicontroller.hpp>
#include <drivers/spi/spidevice.hpp>
#include <sleepmanager.hpp>

#include "mytask.hpp"

// SleepManager &sleepManager   = SleepManager::getInstance();
SpiController &spiController = SpiController::getInstance();

SpiDevice spi(SPI0, 1);
Gpio ce(EXT1_PIN_5);
Gpio irq(EXT1_PIN_9);

// Gpio led(LED_0_PIN);
// Gpio button(BUTTON_0_PIN);

RF24 rf24(spi, ce, irq);
MyTask myTask(rf24);

int main() {
    sysclk_init();

    board_init();

    // sysclk_enable_peripheral_clock(ID_XDMAC);

    // sleepManager.init();
    spiController.enableMasterMode(SPI0);
    spi.init(0, 10000000);

    ce.init(IOPORT_DIR_OUTPUT);
    // irq.init(IOPORT_DIR_INPUT);

    // NVIC_ClearPendingIRQ(PIN_PUSHBUTTON_1_IRQn);

    // button.init(IOPORT_DIR_INPUT);
    // button.enableInterrupt(
    //     [](void *user) {
    //         LOG("%p", user);
    //         static_cast<Gpio *>(user)->disableInterrupt();
    //     },
    //     &button);

    // NVIC_EnableIRQ(PIN_PUSHBUTTON_1_IRQn);

    LOG("Enter scheduler");

    vTaskStartScheduler();
}

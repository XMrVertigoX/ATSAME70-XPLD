#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nRF24L01/nRF24L01.hpp>
#include <xXx/utils/logging.hpp>

#include "drivers/gpio/gpio.hpp"
#include "drivers/spi/spidevice.hpp"
#include "drivers/spi/spimgr.hpp"

#include "radiotask.hpp"
#include "sleepmgr.hpp"

SleepMgr &sleepManager = SleepMgr::getInstance();
SpiMgr &spiManager     = SpiMgr::getInstance();

// Gpio led(LED_0_PIN);
// Gpio button(BUTTON_0_PIN);

SpiDevice rf24_spi(SPI0, 1);
Gpio rf24_ce(EXT1_PIN_5);
Gpio rf24_irq(EXT1_PIN_9);
nRF24L01 rf24(rf24_spi, rf24_ce, rf24_irq);

RadioTask radioTask(rf24);

int main() {
    sysclk_init();

    board_init();

    // sysclk_enable_peripheral_clock(ID_XDMAC);

    sleepManager.init();
    spiManager.enableMasterMode(SPI0);

    rf24_spi.init(0, 10000000);
    rf24_ce.init(IOPORT_DIR_OUTPUT);
    rf24_irq.init(IOPORT_DIR_INPUT);

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

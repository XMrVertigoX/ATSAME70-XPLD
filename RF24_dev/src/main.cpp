#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/rf24/rf24.hpp>
#include <xXx/utils/logging.hpp>

#include "drivers/gpio.hpp"
#include "drivers/spidevice.hpp"

#include "radiotask.hpp"

drivers::SpiDevice rf24_spi(SPI0, 1);
drivers::Gpio rf24_irq(EXT1_PIN_9);
drivers::Gpio rf24_ce(EXT1_PIN_10);

xXx::RF24 rf24(rf24_spi, rf24_ce, rf24_irq);

RadioTask radioTask(rf24);

int main() {
    sysclk_init();
    board_init();

    NVIC_EnableIRQ(PIOD_IRQn);  // rf24_irq

    rf24_spi.init(0, 10000000);
    rf24_irq.init(IOPORT_DIR_INPUT);
    rf24_ce.init(IOPORT_DIR_OUTPUT);

    radioTask.create(configMINIMAL_STACK_SIZE, Task_Priority_LOW);

    delay_ms(100);

    LOG("Enter scheduler\n");

    vTaskStartScheduler();
}

#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/utils/logging.hpp>

#include "drivers/gpio/gpio.hpp"
#include "drivers/spi/spidevice.hpp"

#include "radiotask.hpp"

SpiDevice rf24_spi(SPI0, 1);
Gpio rf24_irq(EXT1_PIN_9);
Gpio rf24_ce(EXT1_PIN_10);
RF24_ESB rf24(rf24_spi, rf24_ce, rf24_irq);

RadioTask radioTask(rf24);

int main() {
    sysclk_init();
    board_init();

    NVIC_EnableIRQ(PIOD_IRQn);  // rf24_irq

    rf24_spi.init(0, 10000000);
    rf24_irq.init(IOPORT_DIR_INPUT);
    rf24_ce.init(IOPORT_DIR_OUTPUT);

    //    rf24.create(configMINIMAL_STACK_SIZE, Task_Priority_LOW);
    radioTask.create(configMINIMAL_STACK_SIZE, Task_Priority_MID);

    delay_ms(100);

    LOG("Enter scheduler");

    vTaskStartScheduler();
}

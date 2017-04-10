#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/components/wireless/nrf24l01p/nrf24l01p_esb.hpp>
#include <xXx/utils/logging.hpp>

#include "drivers/gpio/gpio.hpp"
#include "drivers/spi/spidevice.hpp"
#include "drivers/spi/spimgr.hpp"

#include "radiotask.hpp"

SpiMgr &spiManager = SpiMgr::getInstance();

Gpio led(LED_0_PIN);
Gpio button(BUTTON_0_PIN);

SpiDevice rf24_spi(SPI0, 1);
Gpio rf24_irq(EXT1_PIN_9);
Gpio rf24_ce(EXT1_PIN_10);
nRF24L01P_ESB rf24(rf24_spi, rf24_ce, rf24_irq);

RadioTask radioTask(rf24);

int main() {
    sysclk_init();
    board_init();

    NVIC_EnableIRQ(PIOA_IRQn);  // button
    NVIC_EnableIRQ(PIOD_IRQn);  // rf24_irq

    spiManager.enableMasterMode(SPI0);

    rf24_spi.init(0, 10000000);
    rf24_ce.init(IOPORT_DIR_OUTPUT);
    rf24_irq.init(IOPORT_DIR_INPUT);

    button.init(IOPORT_DIR_INPUT);
    button.enableInterrupt([](void *user) { led.toggle(); }, NULL);

    rf24.taskCreate();
    radioTask.taskCreate();

    delay_ms(100);

    LOG("Enter scheduler");

    vTaskStartScheduler();
}

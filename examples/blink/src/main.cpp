#include <cstdlib>

#include "asf.h"

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

void task(void* user) {
    ioport_set_pin_dir(LED0_GPIO, IOPORT_DIR_OUTPUT);

    for (;;) {
        ioport_set_pin_level(LED0_GPIO, IOPORT_PIN_LEVEL_LOW);
        vTaskDelay(50 / portTICK_PERIOD_MS);
        ioport_set_pin_level(LED0_GPIO, IOPORT_PIN_LEVEL_HIGH);
        vTaskDelay(950 / portTICK_PERIOD_MS);
    }
}

int main() {
    sysclk_init();
    board_init();

    ioport_init();

    xTaskCreate(task, NULL, 256, NULL, 1, NULL);

    log("Enter scheduler\n");

    vTaskStartScheduler();

    return EXIT_FAILURE;
}

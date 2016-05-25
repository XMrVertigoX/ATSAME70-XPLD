extern "C" {
#include <board.h>
}

#include "FreeRTOS.h"
#include "task.h"

void task_blinkLed(void *user) {
    for (;;) {
        LED_Toggle(0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

int main(void) {
    // Disable watchdog
    WDT_Disable(WDT);

    SCB_EnableICache();
    SCB_EnableDCache();

    LED_Configure(0);

    xTaskCreate(task_blinkLed, NULL, 256, NULL, 1, NULL);

    vTaskStartScheduler();

    return 0;
}

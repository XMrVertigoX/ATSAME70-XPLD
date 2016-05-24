#include <stdio.h>
#include <stdbool.h>

extern "C" {
#include "board.h"
}

static void _ConfigureLeds(void) {
    LED_Configure(0);
}

int main(void) {
    // Disable watchdog
    WDT_Disable(WDT);

    SCB_EnableICache();
    SCB_EnableDCache();

    // Configure systick for 1 ms.
    TimeTick_Configure();

    LED_Configure(0);

    while (1) {
        Wait(1000);
        LED_Toggle(0);
    }
}

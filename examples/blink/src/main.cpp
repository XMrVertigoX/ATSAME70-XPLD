#include <stdio.h>

extern "C" {
#include "board.h"
}

int main(void) {
    // Disable watchdog
    WDT_Disable(WDT);

    // Configure systick for 1 ms.
    TimeTick_Configure();

    LED_Configure(0);

    while (1) {
        LED_Toggle(0);
        Wait(500);
    }
}

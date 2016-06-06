#include "asf.h"

#define EXAMPLE_LED LED0_GPIO
#define EXAMPLE_BUTTON GPIO_PUSH_BUTTON_1

int main() {
    sysclk_init();
    board_init();
    ioport_init();

    ioport_set_pin_dir(EXAMPLE_LED, IOPORT_DIR_OUTPUT);

    ioport_set_pin_dir(EXAMPLE_BUTTON, IOPORT_DIR_INPUT);
    ioport_set_pin_mode(EXAMPLE_BUTTON, IOPORT_MODE_PULLUP);

    for (;;) {
        ioport_set_pin_level(EXAMPLE_LED, ioport_get_pin_level(EXAMPLE_BUTTON));
    }
}

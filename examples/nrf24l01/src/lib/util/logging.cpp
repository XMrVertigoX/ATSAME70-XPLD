#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

static const size_t numBytes = 256;
static const char replacementCharacter = '_';

static char bytes[numBytes];

static char getVisibleChararcterRepresentation(char character) {
    if (isprint(character)) {
        return character;
    } else {
        return replacementCharacter;
    }
}

void printVisible(const char *format, ...) {
    portENTER_CRITICAL();

    size_t length;
    va_list args;

    va_start(args, format);
    length = vsnprintf(bytes, sizeof(bytes), format, args);
    va_end(args);

    for (size_t i = 0; i < length; i++) {
        putchar(getVisibleChararcterRepresentation(bytes[i]));
    }

    putchar('\n');

    portEXIT_CRITICAL();
}

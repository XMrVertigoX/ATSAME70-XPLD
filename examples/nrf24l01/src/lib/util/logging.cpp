#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

static const size_t maxNumBytes = 256;
static const char replacementCharacter = '_';

static inline char getVisibleChararcterRepresentation(char character) {
    if (isprint(character)) {
        return character;
    } else {
        return replacementCharacter;
    }
}

void printVisible(const char *format, ...) {
    portENTER_CRITICAL();

    char bytes[maxNumBytes];
    size_t numBytes;

    va_list args;
    va_start(args, format);
    numBytes = vsnprintf(bytes, maxNumBytes, format, args);
    va_end(args);

    for (size_t i = 0; i < numBytes; i++) {
        putchar(getVisibleChararcterRepresentation(bytes[i]));
    }

    putchar('\n');

    portEXIT_CRITICAL();
}

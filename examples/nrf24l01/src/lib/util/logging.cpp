#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#include "logging.hpp"

#define MAX_LOG_LENGTH 256
#define REPLACEMENT_CHARACTER '_'

void putVisibleChararcterRepresentation(char character) {
    if (isprint(character)) {
        putchar(character);
    } else {
        putchar(REPLACEMENT_CHARACTER);
    }
}

void printVisible(const char *format, ...) {
    static char bytes[MAX_LOG_LENGTH];

    size_t numBytes;
    va_list args;

    va_start(args, format);
    numBytes = vsnprintf(bytes, sizeof(bytes), format, args);
    va_end(args);

    for (size_t i = 0; i < numBytes; i++) {
        putVisibleChararcterRepresentation(bytes[i]);
    }

    putchar('\n');
}

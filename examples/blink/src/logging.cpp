#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#include "logging.hpp"

void log(const char *format, ...) {
    char numBytes = 0xFF;
    char bytes[numBytes];

    va_list args;
    va_start(args, format);
    numBytes = vsnprintf(bytes, numBytes, format, args);
    va_end(args);

    for (size_t i = 0; i < numBytes; i++) {
        if (iscntrl(bytes[i])) {
            putchar('_');
        } else {
            putchar(bytes[i]);
        }
    }

    putchar('\n');
}

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "logging.hpp"

static const size_t maxLength = 256;

void log(const char message[]) {
    portENTER_CRITICAL();

    uint32_t millis = xTaskGetTickCount() * portTICK_PERIOD_MS;
    printf("%d.%03d %s\n", millis / 1000, millis % 1000, message);

    portEXIT_CRITICAL();
}

void print(const char *format, ...) {
    uint32_t millis = xTaskGetTickCount() * portTICK_PERIOD_MS;

    char string[maxLength];
    size_t length;

    va_list args;
    va_start(args, format);
    length = vsnprintf(string, maxLength, format, args);
    va_end(args);

    for (size_t i = 0; i < length; i++) {
        if (!isprint(string[i])) {
            string[i] = '_';
        }
    }

    log(string);
}

void printBuffer(const char *message, uint8_t *bytes, uint32_t numBytes) {
    portENTER_CRITICAL();

    uint32_t millis = xTaskGetTickCount() * portTICK_PERIOD_MS;

    printf("%d.%03d %s", millis / 1000, millis % 1000, message);

    for (int i = 0; i < numBytes; ++i) {
        printf(" %02x", bytes[i]);
    }

    fputc('\n', stdout);

    portEXIT_CRITICAL();
}

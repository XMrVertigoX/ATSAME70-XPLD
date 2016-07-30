#ifndef LOGGING_HPP_
#define LOGGING_HPP_

#include "FreeRTOS.h"

#define TIMESTAMP "%03d.%03d - "
#define SECONDS xTaskGetTickCount() / 1000
#define MILLISECONDS xTaskGetTickCount() % 1000

#ifndef NDEBUG
// The "missing" comma (',') between TIMESTAMP and MESSAGE is intended!
#define LOG(MESSAGE, ...) \
    printVisible(TIMESTAMP MESSAGE, SECONDS, MILLISECONDS, ##__VA_ARGS__)
#else
#define LOG(...)
#endif

void printVisible(const char *format, ...);

#endif  // LOGGING_HPP_

#ifndef LOGGING_HPP_
#define LOGGING_HPP_

#include "FreeRTOS.h"
#include "task.h"

#define TIMESTAMP "%d.%03d"
#define FUNCTION "%s"
#define SECONDS (xTaskGetTickCount() * portTICK_PERIOD_MS / 1000)
#define MILLISECONDS (xTaskGetTickCount() * portTICK_PERIOD_MS % 1000)

#ifndef NDEBUG
#define LOG(MESSAGE, ...)                                                    \
    printVisible(TIMESTAMP " " FUNCTION ": " MESSAGE, SECONDS, MILLISECONDS, \
                 __FUNCTION__, ##__VA_ARGS__)
#else
#define LOG(...)
#endif

void printVisible(const char *format, ...);

#endif  // LOGGING_HPP_

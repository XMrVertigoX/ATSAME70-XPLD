#ifndef LOGGING_HPP_
#define LOGGING_HPP_

#include "FreeRTOS.h"
#include "task.h"

#ifndef NDEBUG
#define BUFFER(message, bytes, numBytes) printBuffer(message, bytes, numBytes)
#define LOG(format, ...) print(format, ##__VA_ARGS__)
#else
#define LOG(...)
#define BUFFER(...)
#endif

void print(const char *format, ...);
void printBuffer(const char *message, uint8_t *bytes, uint32_t numBytes);

#endif  // LOGGING_HPP_

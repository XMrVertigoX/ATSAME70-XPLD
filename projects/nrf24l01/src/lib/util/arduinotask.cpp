#include <cstdlib>

#include <FreeRTOS.h>
#include <task.h>

#include "arduinotask.hpp"

#define TASK_FUNCTION                                                 \
    [](void *pvParameters) {                                          \
        ArduinoTask *task = static_cast<ArduinoTask *>(pvParameters); \
        task->setup();                                                \
        for (;;) {                                                    \
            task->loop();                                             \
        }                                                             \
    }

ArduinoTask::~ArduinoTask() {}

BaseType_t ArduinoTask::attachToScheduler(const char *const pcName,
                                          const uint16_t usStackDepth,
                                          UBaseType_t uxPriority,
                                          TaskHandle_t *const pxCreatedTask) {
    BaseType_t status = xTaskCreate(TASK_FUNCTION, pcName, usStackDepth, this,
                                    uxPriority, pxCreatedTask);
    return (status);
}

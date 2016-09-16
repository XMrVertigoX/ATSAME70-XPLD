#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/logging.hpp>

#include "sleepmanager.hpp"

void SleepManager::init() {
    sleepmgr_init();
}

// ----- FreeRTOS hook function -----------------------------------------------

extern "C" void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime) {}

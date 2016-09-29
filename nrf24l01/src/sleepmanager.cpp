#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/logging.hpp>

#include "sleepmanager.hpp"

void SleepManager::init() {
    sleepmgr_init();
    // Init counter/timer
}

uint32_t SleepManager::sleep(TickType_t ticks) {
    // sleepmgr_enter_sleep();
    // TODO: Return actual rtos sleep ticks
    return (0);
}

TickType_t SleepManager::rtc2rtos(uint32_t ticks) {
    // return ((ticks * configTICK_RATE_HZ) / _clockFreqency);
    return (0);
}

uint32_t SleepManager::rtos2rtc(TickType_t ticks) {
    // return ((ticks * _clockFreqency) / configTICK_RATE_HZ);
    return (0);
}

// ----- FreeRTOS hook function -----------------------------------------------

void vPortSuppressTicksAndSleep(TickType_t expectedSleepTicks) {
    uint32_t actualSleepTicks = 0;

    SleepManager &sleepManager = SleepManager::getInstance();
    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    if (eSleepStatus == eAbortSleep) {
        return;
    }

    // TODO: Disable timer/interrupts here
    taskDISABLE_INTERRUPTS();

    if (eSleepStatus == eStandardSleep) {
        actualSleepTicks = sleepManager.sleep(expectedSleepTicks);
    } else {
        actualSleepTicks = sleepManager.sleep();
    }

    vTaskStepTick(actualSleepTicks);

    // TODO: Enable timer/interrupts here
    taskENABLE_INTERRUPTS();
}

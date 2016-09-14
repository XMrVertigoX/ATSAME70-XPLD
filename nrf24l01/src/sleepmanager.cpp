#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/logging.hpp>

#include "sleepmanager.hpp"

void SleepManager::init() {
    sleepmgr_init();
}

// ----- FreeRTOS hook functions ----------------------------------------------

extern "C" void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime) {
    unsigned long ulLowPowerTimeBeforeSleep, ulLowPowerTimeAfterSleep;

    // ulLowPowerTimeBeforeSleep = ulGetExternalTime();

    taskDISABLE_INTERRUPTS();

    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    switch (eSleepStatus) {
        case eAbortSleep:
            break;
        case eStandardSleep:
            /* Configure an interrupt to bring the microcontroller out of its
             * low power state at the time the kernel next needs to execute.
             * The interrupt must be generated from a source that remains
             * operational when the microcontroller is in a low power state. */
            // vSetWakeTimeInterrupt(xExpectedIdleTime);

            /* Enter the low power state. */
            sleepmgr_enter_sleep();

            /* Determine how long the microcontroller was actually in a low
             * power state for, which will be less than xExpectedIdleTime if
             * the microcontroller was brought out of low power mode by an
             * interrupt other than that configured by the
             * vSetWakeTimeInterrupt() call. Note that the scheduler is
             * suspended before portSUPPRESS_TICKS_AND_SLEEP() is called, and
             * resumed when portSUPPRESS_TICKS_AND_SLEEP() returns.  Therefore
             * no other tasks will execute until this function completes. */
            // ulLowPowerTimeAfterSleep = ulGetExternalTime();

            /* Correct the kernels tick count to account for the time the
             * microcontroller spent in its low power state. */
            // vTaskStepTick(ulLowPowerTimeAfterSleep – ulLowPowerTimeBeforeSleep);
            break;
        case eNoTasksWaitingTimeout:
            sleepmgr_enter_sleep();
            break;
    }

    taskENABLE_INTERRUPTS();
}

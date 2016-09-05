#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/logging.hpp>

#include "sleepmanager.hpp"

void SleepManager::init() {}

// ----- FreeRTOS hook function -----------------------------------------------

/* Define the function that is called by portSUPPRESS_TICKS_AND_SLEEP(). */
extern "C" void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime) {
    unsigned long ulLowPowerTimeBeforeSleep, ulLowPowerTimeAfterSleep;
    eSleepModeStatus eSleepStatus;

    //    /* Read the current time from a time source that will remain operational
    //    while the microcontroller is in a low power state. */
    //    ulLowPowerTimeBeforeSleep = ulGetExternalTime();
    //
    //    /* Stop the timer that is generating the tick interrupt. */
    //    prvStopTickInterruptTimer();
    //
    //    /* Enter a critical section that will not effect interrupts bringing the MCU
    //    out of sleep mode. */
    //    disable_interrupts();
    //
    //    /* Ensure it is still ok to enter the sleep mode. */
    //    eSleepStatus = eTaskConfirmSleepModeStatus();
    //
    //    if (eSleepStatus == eAbortSleep) {
    //        /* A task has been moved out of the Blocked state since this macro was
    //        executed, or a context siwth is being held pending.  Do not enter a
    //        sleep state.  Restart the tick and exit the critical section. */
    //        prvStartTickInterruptTimer();
    //        enable_interrupts();
    //    } else {
    //        if (eSleepStatus == eNoTasksWaitingTimeout) {
    //            /* It is not necessary to configure an interrupt to bring the
    //            microcontroller out of its low power state at a fixed time in the
    //            future. */
    //            prvSleep();
    //        } else {
    //            /* Configure an interrupt to bring the microcontroller out of its low
    //            power state at the time the kernel next needs to execute.  The
    //            interrupt must be generated from a source that remains operational
    //            when the microcontroller is in a low power state. */
    //            vSetWakeTimeInterrupt(xExpectedIdleTime);
    //
    //            /* Enter the low power state. */
    //            prvSleep();
    //
    //            /* Determine how long the microcontroller was actually in a low power
    //            state for, which will be less than xExpectedIdleTime if the
    //            microcontroller was brought out of low power mode by an interrupt
    //            other than that configured by the vSetWakeTimeInterrupt() call.
    //            Note that the scheduler is suspended before
    //            portSUPPRESS_TICKS_AND_SLEEP() is called, and resumed when
    //            portSUPPRESS_TICKS_AND_SLEEP() returns.  Therefore no other tasks will
    //            execute until this function completes. */
    //            ulLowPowerTimeAfterSleep = ulGetExternalTime();
    //
    //            /* Correct the kernels tick count to account for the time the
    //            microcontroller spent in its low power state. */
    //            vTaskStepTick(ulLowPowerTimeAfterSleep – ulLowPowerTimeBeforeSleep);
    //        }
    //
    //        /* Exit the critical section - it might be possible to do this immediately
    //        after the prvSleep() calls. */
    //        enable_interrupts();
    //
    //        /* Restart the timer that is generating the tick interrupt. */
    //        prvStartTickInterruptTimer();
    //    }
}

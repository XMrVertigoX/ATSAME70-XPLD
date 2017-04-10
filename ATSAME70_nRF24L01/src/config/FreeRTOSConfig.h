#ifndef FREERTOS_CONFIG_H_
#define FREERTOS_CONFIG_H_

#include <assert.h>

#include <asf.h>

// clang-format off

#define configASSERT(x)                      assert(x)
#define configCHECK_FOR_STACK_OVERFLOW       (0)
#define configCPU_CLOCK_HZ                   (SystemCoreClock)
#define configMAX_PRIORITIES                 (4)
#define configMINIMAL_STACK_SIZE             (256)
#define configTICK_RATE_HZ                   (1000)
#define configTOTAL_HEAP_SIZE                (32768)
#define configUSE_16_BIT_TICKS               (0)
#define configUSE_IDLE_HOOK                  (0)
#define configUSE_MALLOC_FAILED_HOOK         (0)
#define configUSE_PREEMPTION                 (1)
#define configUSE_TICK_HOOK                  (0)
#define configUSE_TICKLESS_IDLE              (0)

#define configKERNEL_INTERRUPT_PRIORITY      (0xFF ^ (0 << (8 - __NVIC_PRIO_BITS)))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY (0xFF ^ (7 << (8 - __NVIC_PRIO_BITS)))

#define INCLUDE_vTaskPrioritySet             (1)
#define INCLUDE_uxTaskPriorityGet            (1)
#define INCLUDE_vTaskDelete                  (1)
#define INCLUDE_vTaskSuspend                 (1)
#define INCLUDE_xResumeFromISR               (1)
#define INCLUDE_vTaskDelayUntil              (1)
#define INCLUDE_vTaskDelay                   (1)
#define INCLUDE_xTaskGetSchedulerState       (1)
#define INCLUDE_xTaskGetCurrentTaskHandle    (1)
#define INCLUDE_uxTaskGetStackHighWaterMark  (1)
#define INCLUDE_xTaskGetIdleTaskHandle       (1)
#define INCLUDE_eTaskGetState                (1)
#define INCLUDE_xEventGroupSetBitFromISR     (0)
#define INCLUDE_xTimerPendFunctionCall       (0)
#define INCLUDE_xTaskAbortDelay              (1)
#define INCLUDE_xTaskGetHandle               (1)
#define INCLUDE_xTaskResumeFromISR           (1)

#define xPortPendSVHandler(x)                PendSV_Handler(x)
#define vPortSVCHandler(x)                   SVC_Handler(x)
#define xPortSysTickHandler(x)               SysTick_Handler(x)

// clang-format on

#endif /* FREERTOS_CONFIG_H_ */

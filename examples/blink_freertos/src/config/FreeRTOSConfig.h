#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configCPU_CLOCK_HZ 12000000
#define configMAX_PRIORITIES 4
#define configMINIMAL_STACK_SIZE 128
#define configTICK_RATE_HZ 1000

// Use 128K ram for heap
#define configTOTAL_HEAP_SIZE 8192
#define configUSE_16_BIT_TICKS 0
#define configUSE_IDLE_HOOK 0
#define configUSE_PREEMPTION 1
#define configUSE_TICK_HOOK 0

#define INCLUDE_vTaskPrioritySet 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1

// Interrupt nesting behaviour configuration.
#define configKERNEL_INTERRUPT_PRIORITY 0xFF
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 0xA0  // equivalent priority 5.

// Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
// standard names.
#define xPortPendSVHandler PendSV_Handler
#define vPortSVCHandler SVC_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */

FREERTOS_DIR = ../../FreeRTOS

# ----- Include directories ----------------------------------------------------

INCLUDE_DIRS += $(FREERTOS_DIR)/include
INCLUDE_DIRS += $(FREERTOS_DIR)/portable/GCC/ARM_CM7/r0p1

# ----- Source files -----------------------------------------------------------

SOURCE_FILES += $(wildcard $(FREERTOS_DIR)/*.c)
SOURCE_FILES += $(FREERTOS_DIR)/portable/GCC/ARM_CM7/r0p1/port.c
SOURCE_FILES += $(FREERTOS_DIR)/portable/MemMang/heap_3.c

ASF = ../libs/ASF

# ----- Files and folders -----------------------------------------------------

CMSIS    = $(ASF)/thirdparty/CMSIS
COMMON   = $(ASF)/common
FREERTOS = $(ASF)/thirdparty/freertos/freertos-8.2.3/Source
SAM      = $(ASF)/sam

# ----- Symbols ---------------------------------------------------------------

SYMBOLS += __SAME70Q21__
SYMBOLS += BOARD=SAME70_XPLAINED

# ----- Source files and header -----------------------------------------------

# CMSIS
INCLUDE_DIRS += $(CMSIS)/Include
LIBRARY_DIRS += $(CMSIS)/Lib/GCC

# Common
INCLUDE_DIRS += $(COMMON)/boards
INCLUDE_DIRS += $(COMMON)/services/clock
INCLUDE_DIRS += $(COMMON)/services/delay
INCLUDE_DIRS += $(COMMON)/services/ioport
INCLUDE_DIRS += $(COMMON)/services/sleepmgr
INCLUDE_DIRS += $(COMMON)/utils

SOURCE_FILES += $(COMMON)/services/clock/same70/sysclk.c
SOURCE_FILES += $(COMMON)/services/delay/sam/cycle_counter.c
SOURCE_FILES += $(COMMON)/services/sleepmgr/sam/sleepmgr.c
SOURCE_FILES += $(COMMON)/utils/interrupt/interrupt_sam_nvic.c

# FreeRTOS
INCLUDE_DIRS += $(FREERTOS)/include
INCLUDE_DIRS += $(FREERTOS)/portable/GCC/ARM_CM7/r0p1

SOURCE_FILES += $(FREERTOS)/croutine.c
SOURCE_FILES += $(FREERTOS)/event_groups.c
SOURCE_FILES += $(FREERTOS)/list.c
SOURCE_FILES += $(FREERTOS)/queue.c
SOURCE_FILES += $(FREERTOS)/tasks.c
SOURCE_FILES += $(FREERTOS)/timers.c
SOURCE_FILES += $(FREERTOS)/portable/GCC/ARM_CM7/r0p1/port.c
SOURCE_FILES += $(FREERTOS)/portable/MemMang/heap_4.c

# Sam
INCLUDE_DIRS += $(SAM)/boards
INCLUDE_DIRS += $(SAM)/boards/same70_xplained
INCLUDE_DIRS += $(SAM)/drivers/pio
INCLUDE_DIRS += $(SAM)/drivers/pmc
INCLUDE_DIRS += $(SAM)/drivers/spi
INCLUDE_DIRS += $(SAM)/drivers/xdmac
INCLUDE_DIRS += $(SAM)/utils
INCLUDE_DIRS += $(SAM)/utils/cmsis/same70/include
INCLUDE_DIRS += $(SAM)/utils/cmsis/same70/source/templates
INCLUDE_DIRS += $(SAM)/utils/fpu
INCLUDE_DIRS += $(SAM)/utils/header_files
INCLUDE_DIRS += $(SAM)/utils/preprocessor

SOURCE_FILES += $(SAM)/boards/same70_xplained/init.c
SOURCE_FILES += $(SAM)/drivers/pio/pio.c
SOURCE_FILES += $(SAM)/drivers/pio/pio_handler.c
SOURCE_FILES += $(SAM)/drivers/pmc/pmc.c
SOURCE_FILES += $(SAM)/drivers/pmc/sleep.c
SOURCE_FILES += $(SAM)/drivers/spi/spi.c
SOURCE_FILES += $(SAM)/drivers/xdmac/xdmac.c
SOURCE_FILES += $(SAM)/utils/cmsis/same70/source/templates/system_same70.c
SOURCE_FILES += $(SAM)/utils/cmsis/same70/source/templates/gcc/startup_same70.c
SOURCE_FILES += $(SAM)/utils/syscalls/gcc/syscalls.c

# ----- Libraries -------------------------------------------------------------

LIBRARIES += arm_cortexM7lfdp_math

# ----- Flags -----------------------------------------------------------------

LINKER_SCRIPT = $(SAM)/utils/linker_scripts/same70/same70q21/gcc/flash.ld
LDFLAGS += -T $(realpath $(LINKER_SCRIPT))

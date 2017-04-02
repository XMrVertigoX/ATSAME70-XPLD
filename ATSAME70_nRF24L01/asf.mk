# ----- Files and folders -----------------------------------------------------

ASF = ../libs/asf-standalone-archive-3.33.0.50/xdk-asf-3.33.0

# ----- Symbols ---------------------------------------------------------------

SYMBOLS += __SAME70Q21__
SYMBOLS += BOARD=SAME70_XPLAINED

# ----- Source files and header -----------------------------------------------

INCLUDE_DIRS += $(ASF)/common/boards
INCLUDE_DIRS += $(ASF)/common/services/clock
INCLUDE_DIRS += $(ASF)/common/services/delay
INCLUDE_DIRS += $(ASF)/common/services/ioport
INCLUDE_DIRS += $(ASF)/common/services/sleepmgr
INCLUDE_DIRS += $(ASF)/common/utils
INCLUDE_DIRS += $(ASF)/sam/boards
INCLUDE_DIRS += $(ASF)/sam/boards/same70_xplained
INCLUDE_DIRS += $(ASF)/sam/drivers/pio
INCLUDE_DIRS += $(ASF)/sam/drivers/pmc
INCLUDE_DIRS += $(ASF)/sam/drivers/spi
INCLUDE_DIRS += $(ASF)/sam/drivers/xdmac
INCLUDE_DIRS += $(ASF)/sam/utils
INCLUDE_DIRS += $(ASF)/sam/utils/cmsis/same70/include
INCLUDE_DIRS += $(ASF)/sam/utils/cmsis/same70/source/templates
INCLUDE_DIRS += $(ASF)/sam/utils/fpu
INCLUDE_DIRS += $(ASF)/sam/utils/header_files
INCLUDE_DIRS += $(ASF)/sam/utils/preprocessor
INCLUDE_DIRS += $(ASF)/thirdparty/CMSIS/Include
INCLUDE_DIRS += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/include
INCLUDE_DIRS += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/portable/GCC/ARM_CM7/r0p1

SOURCE_FILES += $(ASF)/common/services/clock/same70/sysclk.c
SOURCE_FILES += $(ASF)/common/services/delay/sam/cycle_counter.c
SOURCE_FILES += $(ASF)/common/services/sleepmgr/sam/sleepmgr.c
SOURCE_FILES += $(ASF)/common/utils/interrupt/interrupt_sam_nvic.c
SOURCE_FILES += $(ASF)/sam/boards/same70_xplained/init.c
SOURCE_FILES += $(ASF)/sam/drivers/pio/pio_handler.c
SOURCE_FILES += $(ASF)/sam/drivers/pio/pio.c
SOURCE_FILES += $(ASF)/sam/drivers/pmc/pmc.c
SOURCE_FILES += $(ASF)/sam/drivers/pmc/sleep.c
SOURCE_FILES += $(ASF)/sam/drivers/spi/spi.c
SOURCE_FILES += $(ASF)/sam/drivers/xdmac/xdmac.c
SOURCE_FILES += $(ASF)/sam/utils/cmsis/same70/source/templates/gcc/startup_same70.c
SOURCE_FILES += $(ASF)/sam/utils/cmsis/same70/source/templates/system_same70.c
SOURCE_FILES += $(ASF)/sam/utils/syscalls/gcc/syscalls.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/croutine.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/event_groups.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/list.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/portable/GCC/ARM_CM7/r0p1/port.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/portable/MemMang/heap_4.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/queue.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/tasks.c
SOURCE_FILES += $(ASF)/thirdparty/freertos/freertos-8.2.3/Source/timers.c

# ----- Libraries -------------------------------------------------------------

LIBRARY_DIRS += $(ASF)/thirdparty/CMSIS/Lib/GCC

LIBRARIES += arm_cortexM7lfdp_math

# ----- Flags -----------------------------------------------------------------

LINKER_SCRIPT = $(ASF)/sam/utils/linker_scripts/same70/same70q21/gcc/flash.ld
LDFLAGS += -T $(realpath $(LINKER_SCRIPT))

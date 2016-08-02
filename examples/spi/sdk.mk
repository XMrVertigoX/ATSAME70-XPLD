SDK_DIR = ../../ASF/xdk-asf-3.32.0

# ----- Symbols ----------------------------------------------------------------

SYMBOLS += __SAME70Q21__
SYMBOLS += BOARD=SAME70_XPLAINED
SYMBOLS += ARM_MATH_CM7=true
SYMBOLS += printf=iprintf
SYMBOLS += scanf=iscanf

# ----- Include directories ----------------------------------------------------

INCLUDE_DIRS += $(SDK_DIR)/common/boards
INCLUDE_DIRS += $(SDK_DIR)/common/services/clock
INCLUDE_DIRS += $(SDK_DIR)/common/services/gpio
INCLUDE_DIRS += $(SDK_DIR)/common/services/ioport
INCLUDE_DIRS += $(SDK_DIR)/common/services/delay
INCLUDE_DIRS += $(SDK_DIR)/common/utils

INCLUDE_DIRS += $(SDK_DIR)/sam/boards
INCLUDE_DIRS += $(SDK_DIR)/sam/boards/same70_xplained

INCLUDE_DIRS += $(SDK_DIR)/sam/drivers/mpu
INCLUDE_DIRS += $(SDK_DIR)/sam/drivers/pio
INCLUDE_DIRS += $(SDK_DIR)/sam/drivers/pmc
INCLUDE_DIRS += $(SDK_DIR)/sam/drivers/spi

INCLUDE_DIRS += $(SDK_DIR)/sam/utils
INCLUDE_DIRS += $(SDK_DIR)/sam/utils/cmsis/same70/include
INCLUDE_DIRS += $(SDK_DIR)/sam/utils/cmsis/same70/source/templates
INCLUDE_DIRS += $(SDK_DIR)/sam/utils/fpu
INCLUDE_DIRS += $(SDK_DIR)/sam/utils/header_files
INCLUDE_DIRS += $(SDK_DIR)/sam/utils/preprocessor

INCLUDE_DIRS += $(SDK_DIR)/thirdparty/CMSIS/Include

# ----- Source files -----------------------------------------------------------

SOURCE_FILES += $(SDK_DIR)/common/services/clock/same70/sysclk.c
SOURCE_FILES += $(SDK_DIR)/common/services/delay/sam/cycle_counter.c
SOURCE_FILES += $(SDK_DIR)/common/utils/interrupt/interrupt_sam_nvic.c
SOURCE_FILES += $(SDK_DIR)/sam/boards/same70_xplained/init.c
SOURCE_FILES += $(SDK_DIR)/sam/drivers/mpu/mpu.c
SOURCE_FILES += $(SDK_DIR)/sam/drivers/pio/pio.c
SOURCE_FILES += $(SDK_DIR)/sam/drivers/pio/pio_handler.c
SOURCE_FILES += $(SDK_DIR)/sam/drivers/pmc/pmc.c
SOURCE_FILES += $(SDK_DIR)/sam/drivers/pmc/sleep.c
SOURCE_FILES += $(SDK_DIR)/sam/drivers/spi/spi.c
SOURCE_FILES += $(SDK_DIR)/sam/utils/cmsis/same70/source/templates/system_same70.c
SOURCE_FILES += $(SDK_DIR)/sam/utils/cmsis/same70/source/templates/gcc/startup_same70.c
SOURCE_FILES += $(SDK_DIR)/sam/utils/syscalls/gcc/syscalls.c

# ----- Libraries --------------------------------------------------------------

LIBS += arm_cortexM7lfdp_math_softfp
LIB_DIRS += $(SDK_DIR)/thirdparty/CMSIS/Lib/GCC

# ----- Flags ------------------------------------------------------------------

GCCFLAGS += -march=armv7-m
GCCFLAGS += -mtune=cortex-m7
GCCFLAGS += -mthumb

CFLAGS   += -mfloat-abi=softfp -mfpu=fpv5-d16
CXXFLAGS += -mfloat-abi=softfp -mfpu=fpv5-d16

LINKER_SCRIPT_FLASH = $(SDK_DIR)/sam/utils/linker_scripts/same70/same70q21/gcc/flash.ld

LDFLAGS += -Wl,--script=$(realpath $(LINKER_SCRIPT_FLASH))

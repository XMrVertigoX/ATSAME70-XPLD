# ----- Files and folders ----------------------------------------------------

SDK_DIR = ../../ASF/xdk-asf-3.32.0

COMMON = $(SDK_DIR)/common
SAM = $(SDK_DIR)/sam
THIRDPARTY = $(SDK_DIR)/thirdparty

LINKER_SCRIPT = $(SAM)/utils/linker_scripts/same70/same70q21/gcc/flash.ld

# ----- Symbols --------------------------------------------------------------

SYMBOLS += __SAME70Q21__
SYMBOLS += BOARD=SAME70_XPLAINED
SYMBOLS += ARM_MATH_CM7=true
# SYMBOLS += printf=iprintf
# SYMBOLS += scanf=iscanf

# ----- ASF ------------------------------------------------------------------

INCLUDE_DIRS += $(COMMON)/boards
INCLUDE_DIRS += $(COMMON)/services/clock
INCLUDE_DIRS += $(COMMON)/services/gpio
INCLUDE_DIRS += $(COMMON)/services/ioport
INCLUDE_DIRS += $(COMMON)/services/delay
INCLUDE_DIRS += $(COMMON)/utils
INCLUDE_DIRS += $(SAM)/boards
INCLUDE_DIRS += $(SAM)/boards/same70_xplained
INCLUDE_DIRS += $(SAM)/drivers/mpu
INCLUDE_DIRS += $(SAM)/drivers/pio
INCLUDE_DIRS += $(SAM)/drivers/pmc
INCLUDE_DIRS += $(SAM)/drivers/spi
INCLUDE_DIRS += $(SAM)/utils
INCLUDE_DIRS += $(SAM)/utils/cmsis/same70/include
INCLUDE_DIRS += $(SAM)/utils/cmsis/same70/source/templates
INCLUDE_DIRS += $(SAM)/utils/fpu
INCLUDE_DIRS += $(SAM)/utils/header_files
INCLUDE_DIRS += $(SAM)/utils/preprocessor

SOURCE_FILES += $(COMMON)/services/clock/same70/sysclk.c
SOURCE_FILES += $(COMMON)/services/delay/sam/cycle_counter.c
SOURCE_FILES += $(COMMON)/utils/interrupt/interrupt_sam_nvic.c
SOURCE_FILES += $(SAM)/boards/same70_xplained/init.c
SOURCE_FILES += $(SAM)/drivers/mpu/mpu.c
SOURCE_FILES += $(SAM)/drivers/pio/pio.c
SOURCE_FILES += $(SAM)/drivers/pio/pio_handler.c
SOURCE_FILES += $(SAM)/drivers/pmc/pmc.c
SOURCE_FILES += $(SAM)/drivers/pmc/sleep.c
SOURCE_FILES += $(SAM)/drivers/spi/spi.c
SOURCE_FILES += $(SAM)/utils/cmsis/same70/source/templates/system_same70.c
SOURCE_FILES += $(SAM)/utils/cmsis/same70/source/templates/gcc/startup_same70.c
SOURCE_FILES += $(SAM)/utils/syscalls/gcc/syscalls.c

# ----- CMSIS ----------------------------------------------------------------

INCLUDE_DIRS += $(THIRDPARTY)/CMSIS/Include

LIB_DIRS += $(THIRDPARTY)/CMSIS/Lib/GCC

# ----- Libraries ------------------------------------------------------------

LIBS += arm_cortexM7lfdp_math_softfp

# ----- Flags ----------------------------------------------------------------

COMMON_CFLAGS += -mfloat-abi=softfp
COMMON_CFLAGS += -mfpu=fpv5-d16

LDFLAGS += -T $(realpath $(LINKER_SCRIPT))
# LDFLAGS += -u _printf_float
# LDFLAGS += -u _scanf_float

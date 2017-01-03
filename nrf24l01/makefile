# ----- Configuration ---------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-
PROJECT_NAME     = nrf24l01

# ----- Sources ---------------------------------------------------------------

include asf.mk

# SYMBOLS += NDEBUG
SYMBOLS += ARM_MATH_CM7
SYMBOLS += __FPU_PRESENT

# >>> Libraries
INCLUDE_DIRS += ../libs

SOURCE_FILES += $(shell find ../libs/xXx -iregex ".*\.\(c\|cpp\|s\)")
SOURCE_FILES += $(shell find ../libs/SEGGER_RTT -iregex ".*\.\(c\|cpp\|s\)")
# <<< Libraries

# >>> Project
INCLUDE_DIRS += src
INCLUDE_DIRS += src/config

SOURCE_FILES += $(shell find src -iregex ".*\.\(c\|cpp\|s\)")
# <<< Project

# ----- Libraries -------------------------------------------------------------

LIBRARIES +=

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -mcpu=cortex-m7
GCCFLAGS += -mthumb
GCCFLAGS += -mfloat-abi=hard
GCCFLAGS += -mfpu=fpv5-d16

COMMON_CFLAGS += -g
COMMON_CFLAGS += -Og

CFLAGS += -std=gnu11

CXXFLAGS += -std=gnu++14

CPPFLAGS +=

# ----- Rules -----------------------------------------------------------------

include ../libs/xXx/utils/rules.mk

download: $(EXECUTABLE)
	arm-none-eabi-gdb -q -x download.gdb $<

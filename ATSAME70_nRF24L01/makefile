# ----- Configuration ---------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-
PROJECT_NAME     = nrf24l01

# ----- Sources ---------------------------------------------------------------

include asf.mk

SYMBOLS += ARM_MATH_CM7
SYMBOLS += __FPU_PRESENT=1

# >>> Libraries
INCLUDE_DIRS += ../libs

SOURCE_FILES += $(wildcard ../libs/xXx/components/wireless/nrf24l01p/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/os/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/support/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/utils/*.cpp)

INCLUDE_DIRS += ../libs/SEGGER_RTT_V612a/RTT
SOURCE_FILES += ../libs/SEGGER_RTT_V612a/RTT/SEGGER_RTT.c
# <<< Libraries

# >>> Project
INCLUDE_DIRS += ./src/config
SOURCE_FILES += $(shell find ./src -iregex ".*\.\(c\|cpp\|s\)")
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

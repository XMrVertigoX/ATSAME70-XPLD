# ----- Configuration ---------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-
PROJECT_NAME     = nrf24l01

# ----- Sources ---------------------------------------------------------------

include asf.mk

# SYMBOLS += NDEBUG

INCLUDE_DIRS += ../libs
SOURCE_FILES += $(wildcard ../libs/xXx/components/wireless/nrf24l01p/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/os/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/support/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/utils/*.cpp)

INCLUDE_DIRS += src
INCLUDE_DIRS += src/config
INCLUDE_DIRS += src/rtt

SOURCE_FILES += $(shell find ./src -type f -name *.c)
SOURCE_FILES += $(shell find ./src -type f -name *.cpp)

# ----- Libraries -------------------------------------------------------------

# LIBRARIES +=

# ----- Flags -----------------------------------------------------------------

GCCFLAGS      += -march=armv7-m
GCCFLAGS      += -mtune=cortex-m7
GCCFLAGS      += -mthumb

COMMON_CFLAGS += -g
COMMON_CFLAGS += -Og

CFLAGS        += -std=gnu11

CXXFLAGS      += -std=gnu++14

LDFLAGS       += 

# ----- Rules -----------------------------------------------------------------

include ../libs/xXx/utils/rules.mk

download: $(EXECUTABLE)
	arm-none-eabi-gdb -q -x download.gdb $<

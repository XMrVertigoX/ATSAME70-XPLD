# ----- Configuration ---------------------------------------------------------

PROJECT_NAME = nrf24l01

# ----- Sources ---------------------------------------------------------------

include asf.mk

# SYMBOLS += NDEBUG

INCLUDE_DIRS += ../libs
SOURCE_FILES += $(wildcard ../libs/xXx/components/wireless/nrf24l01p/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/support/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/utils/*.cpp)

INCLUDE_DIRS += src
INCLUDE_DIRS += src/config
INCLUDE_DIRS += src/rtt

SOURCE_FILES += $(shell find ./src -type f -name *.c)
SOURCE_FILES += $(shell find ./src -type f -name *.cpp)

# ----- Libraries -------------------------------------------------------------

# LIBRARY_DIRS +=
# LIBRARIES +=

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -march=armv7-m
GCCFLAGS += -mtune=cortex-m7
GCCFLAGS += -mthumb

COMMON_CFLAGS += -fdata-sections
COMMON_CFLAGS += -ffunction-sections
COMMON_CFLAGS += -fno-exceptions
COMMON_CFLAGS += -fno-unwind-tables
COMMON_CFLAGS += -g3
COMMON_CFLAGS += -nostdlib
COMMON_CFLAGS += -Og

CFLAGS += -std=gnu11

CXXFLAGS += -fno-rtti
CXXFLAGS += -fno-threadsafe-statics
CXXFLAGS += -std=gnu++14

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules -----------------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-

include ../libs/xXx/utils/rules.mk

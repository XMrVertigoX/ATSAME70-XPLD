# ----- Configuration ---------------------------------------------------------

include config.mk

PROJECT_NAME = nrf24l01

# ----- Sources ---------------------------------------------------------------

include asf.mk

# Project
SYMBOLS += LOG_LEVEL=7
#SYMBOLS += NDEBUG

INCLUDE_DIRS += ../libs
SOURCE_FILES += $(shell find ../libs/xXx -type f -name *.cpp)

INCLUDE_DIRS += src/asf
INCLUDE_DIRS += src/config
INCLUDE_DIRS += src/rtt

SOURCE_FILES += $(shell find ./src -type f -name *.c)
SOURCE_FILES += $(shell find ./src -type f -name *.cpp)

# ----- Libraries -------------------------------------------------------------

# LIB_DIRS +=
# LIBS +=

# ----- Flags -----------------------------------------------------------------

COMMON_GCC_FLAGS += -march=armv7-m
COMMON_GCC_FLAGS += -mtune=cortex-m7
COMMON_GCC_FLAGS += -mthumb

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

include rules.mk

# ----- Configuration ---------------------------------------------------------

include ../config.mk

PROJECT_NAME = nrf24l01

# ----- Sources ---------------------------------------------------------------

include sdk.mk

# SEGGER RTT
INCLUDE_DIRS += ../../SEGGER_RTT
SOURCE_FILES += ../../SEGGER_RTT/SEGGER_RTT.c
SOURCE_FILES += ../../SEGGER_RTT/SEGGER_RTT_Syscalls_GCC.c

# FreeRTOS
INCLUDE_DIRS += ../../FreeRTOS/include
INCLUDE_DIRS += ../../FreeRTOS/portable/GCC/ARM_CM7/r0p1
SOURCE_FILES += $(wildcard ../../FreeRTOS/*.c)
SOURCE_FILES += ../../FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.c
SOURCE_FILES += ../../FreeRTOS/portable/MemMang/heap_3.c

# Project
# SYMBOLS += NDEBUG

INCLUDE_DIRS += src/asf
INCLUDE_DIRS += src/config
INCLUDE_DIRS += src/lib/util

SOURCE_FILES += $(shell find ./src -type f -name *.c)
SOURCE_FILES += $(shell find ./src -type f -name *.cpp)

# ----- Libraries -------------------------------------------------------------

# LIBS +=

# LIB_DIRS +=

# ----- Flags -----------------------------------------------------------------

# GCCFLAGS +=

# CPPFLAGS +=

COMMON_COMPILER_FLAGS = -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -nostdlib

CFLAGS += $(COMMON_COMPILER_FLAGS)
CFLAGS += -std=c11

CXXFLAGS += $(COMMON_COMPILER_FLAGS)
CXXFLAGS += -std=c++17
CXXFLAGS += -fno-rtti
CXXFLAGS += -fno-threadsafe-statics

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules -----------------------------------------------------------------

include ../rules.mk

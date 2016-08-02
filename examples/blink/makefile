# ----- Configuration ----------------------------------------------------------

include ../config.mk

PROJECT_NAME = blink_freertos

# ----- Sources ----------------------------------------------------------------

include sdk.mk

INCLUDE_DIRS += ../../SEGGER_RTT
SOURCE_FILES += $(wildcard ../../SEGGER_RTT/*.c)

INCLUDE_DIRS += ../../FreeRTOS/include
INCLUDE_DIRS += ../../FreeRTOS/portable/GCC/ARM_CM7/r0p1
SOURCE_FILES += $(wildcard ../../FreeRTOS/*.c)
SOURCE_FILES += ../../FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.c
SOURCE_FILES += ../../FreeRTOS/portable/MemMang/heap_3.c

INCLUDE_DIRS += src/config

SOURCE_FILES += $(wildcard src/*.cpp)
SOURCE_FILES += $(wildcard src/support/*.cpp)

# ----- Libraries --------------------------------------------------------------

# LIBS +=

# LIB_DIRS +=

# ----- Flags ------------------------------------------------------------------

# GCCFLAGS +=

# CPPFLAGS +=

COMMON_CFLAGS = -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -nostdlib

CFLAGS += $(COMMON_CFLAGS)

CXXFLAGS += $(COMMON_CFLAGS)
CXXFLAGS += -fno-rtti
CXXFLAGS += -fno-threadsafe-statics

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules ------------------------------------------------------------------

include ../rules.mk

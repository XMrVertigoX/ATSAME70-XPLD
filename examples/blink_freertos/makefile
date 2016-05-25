# ----- Configuration ----------------------------------------------------------

include ../config.mk

PROJECT_NAME = blink_freertos

# ----- Sources ----------------------------------------------------------------

include sdk.mk
include freertos.mk

# SYMBOLS += ARM_MATH_CM7=true
# SYMBOLS += __FPU_PRESENT=1

INCLUDE_DIRS += src/config

SOURCE_FILES += src/main.cpp

# ----- Libraries --------------------------------------------------------------

# LIBS +=

# LIB_DIRS +=

# ----- Flags ------------------------------------------------------------------

GCCFLAGS += -march=armv7-m
GCCFLAGS += -mtune=cortex-m7
GCCFLAGS += -mthumb
GCCFLAGS += -mfloat-abi=softfp
GCCFLAGS += -mfpu=fpv5-d16

# CPPFLAGS +=

COMMON_COMPILER_FLAGS = -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -nostdlib

CFLAGS += $(COMMON_COMPILER_FLAGS)
CFLAGS += -std=c11

CXXFLAGS += $(COMMON_COMPILER_FLAGS)
CXXFLAGS += -std=c++17
CXXFLAGS += -fno-rtti

LDFLAGS += -Wl,--gc-sections
LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs

# ----- Rules ------------------------------------------------------------------

include ../rules.mk

# ----- Configuration ----------------------------------------------------------

include ../config.mk

PROJECT_NAME = button

# ----- Sources ----------------------------------------------------------------

include sdk.mk

INCLUDE_DIRS += src/config
SOURCE_FILES += src/main.cpp

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

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules ------------------------------------------------------------------

include ../rules.mk

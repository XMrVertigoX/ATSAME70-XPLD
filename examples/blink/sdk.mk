SDK_DIR = ../../SDK/same70_softpack_1.5_for_gnu_arm_2015q3/examples/Atmel/SAME70_Xplained

# ----- Symbols ----------------------------------------------------------------

SYMBOLS += __SAME70Q21__
SYMBOLS += BOARD_SAME70_XPLD

# ----- Include directories ----------------------------------------------------

INCLUDE_DIRS += $(SDK_DIR)/libraries/libboard
INCLUDE_DIRS += $(SDK_DIR)/libraries/libboard/include

INCLUDE_DIRS += $(SDK_DIR)/libraries/libchip
INCLUDE_DIRS += $(SDK_DIR)/libraries/libchip/include
INCLUDE_DIRS += $(SDK_DIR)/libraries/libchip/include/same70
INCLUDE_DIRS += $(SDK_DIR)/libraries/libchip/include/cmsis/CMSIS/Include

# ----- Source files -----------------------------------------------------------

SOURCE_FILES += $(SDK_DIR)/libraries/libboard/resources_e70/system_same70.c
SOURCE_FILES += $(SDK_DIR)/libraries/libboard/resources_e70/gcc/startup_same70.c
SOURCE_FILES += $(SDK_DIR)/libraries/libboard/source/board_lowlevel.c
SOURCE_FILES += $(SDK_DIR)/libraries/libboard/source/dbg_console.c
SOURCE_FILES += $(SDK_DIR)/libraries/libboard/source/syscalls.c
SOURCE_FILES += $(SDK_DIR)/libraries/libboard/source/led.c

SOURCE_FILES += $(SDK_DIR)/libraries/libchip/source/mpu.c
SOURCE_FILES += $(SDK_DIR)/libraries/libchip/source/pio.c
SOURCE_FILES += $(SDK_DIR)/libraries/libchip/source/pmc.c
SOURCE_FILES += $(SDK_DIR)/libraries/libchip/source/timetick.c
SOURCE_FILES += $(SDK_DIR)/libraries/libchip/source/wdt.c

# ----- Linker search directories ----------------------------------------------

LIB_DIRS += $(SDK_DIR)/libraries/libboard/resources_e70/gcc/
LIB_DIRS += $(SDK_DIR)/libraries/libchip/include/cmsis/CMSIS/Lib/GCC

# ----- Libraries --------------------------------------------------------------

# LIBS +=

# ----- Flags ------------------------------------------------------------------

LDFLAGS += -Wl,--script=same70q21_flash.ld

# ----- Files -----------------------------------------------------------------

BINARY     = $(OUTPUT_DIR)/$(PROJECT_NAME).bin
EXECUTABLE = $(OUTPUT_DIR)/$(PROJECT_NAME).elf
MAPFILE    = $(OUTPUT_DIR)/$(PROJECT_NAME).map

# ----- Flags -----------------------------------------------------------------

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(realpath $(INCLUDE_DIRS)))

LDFLAGS += $(addprefix -L, $(realpath $(LIB_DIRS)))
LDFLAGS += -Wl,-Map=$(MAPFILE)

LIBFLAGS = $(addprefix -l, $(LIBS))
# LIBFLAGS = -Wl,--start-group $(addprefix -l, $(LIBS)) -Wl,--end-group

# ----- Objects ---------------------------------------------------------------

SORTED_SOURCE_FILES = $(sort $(realpath $(SOURCE_FILES)))
SORTED_OBJECT_FILES = $(addprefix $(OBJECT_DIR),$(addsuffix .o,$(basename $(SORTED_SOURCE_FILES))))

# ----- Rules -----------------------------------------------------------------

.PHONY: all clean download

all: $(EXECUTABLE) $(BINARY)
	@echo # New line for better reading
	$(SIZE) $<
	@echo # Another new line for even better reading

clean:
	@echo [ RMD ] $(OBJECT_DIR) & $(RMDIR) $(OBJECT_DIR)
	@echo [ RMD ] $(OUTPUT_DIR) & $(RMDIR) $(OUTPUT_DIR)

download: $(EXECUTABLE)
	$(GDB) -q -x download.gdb $<

$(OBJECT_DIR)/%.o: /%.c
	@echo [ CMP ] $(notdir $@)
	$(MKDIR) $(dir $@)
	$(GCC) $(COMMON_GCC_FLAGS) $(COMMON_CFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJECT_DIR)/%.o: /%.cpp
	@echo [ CMP ] $(notdir $@)
	$(MKDIR) $(dir $@)
	$(GCC) $(COMMON_GCC_FLAGS) $(COMMON_CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(EXECUTABLE): $(SORTED_OBJECT_FILES)
	@echo [ LNK ] $(notdir $@)
	$(MKDIR) $(dir $@)
	$(GCC) $(COMMON_GCC_FLAGS) $(LDFLAGS) $^ $(LIBFLAGS) -o $@

$(BINARY): $(EXECUTABLE)
	@echo [ CPY ] $(notdir $@)
	$(MKDIR) $(dir $@)
	$(OBJCOPY) -O binary $< $@

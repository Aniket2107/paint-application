#
#       !!!! Do NOT edit this makefile with an editor which replace tabs by spaces !!!!    
#
##############################################################################################
# 
# On command line:
#
# make all = Create project
#
# make clean = Clean project files.
#
# To rebuild project do "make clean" and "make all".
#

##############################################################################################
# Start of default section

TOOLCHAIN = "arm-none-eabi-"

CC   = $(TOOLCHAIN)gcc
CP   = $(TOOLCHAIN)objcopy
AS   = $(TOOLCHAIN)gcc -x assembler-with-cpp
HEX  = $(CP) -O ihex
BIN  = $(CP) -O binary
FILESIZE = $(TOOLCHAIN)size

MCU  = cortex-m3
MCFLAGS = -mcpu=$(MCU)
C_COMPILER_STD = -std=gnu99

# Define optimisation level here
OPT = -O0

#
# End of default section

##############################################################################################
# Start of user section
#

# Define Debug mode, project name
PRIME_DEBUG = 1

# Define Name of you application
TARGET_NAME = userInterface

# User Directory List
INCLUDEDIR	= ../../Include
SOURCEDIR  	= ../../Source

# User Output Directory Path
TARGET_OUT_PATH = Build/Hex
OBJ_PATH	=	Build/Obj

# List C source files here
SRC = 	./main.c				\
		$(SOURCEDIR)/appInit.c			\
		$(SOURCEDIR)/eduarmBoardConfig.c

VPATH = $(SOURCEDIR)

# List ASM source files here
ASRC =

# List all user directories here
UINCDIR = 	$(INCLUDEDIR)						\
			$(INCLUDEDIR)/PrimeFramework		\
			$(INCLUDEDIR)/AppHelper				\
			$(INCLUDEDIR)/GameEngine			\
			$(INCLUDEDIR)/GameEngine/Graphics	\
			$(INCLUDEDIR)/GameEngine/Object		\
			$(INCLUDEDIR)/GameEngine/Renderer	\
			$(INCLUDEDIR)/GameEngine/Resource

# List the user directory to look for the libraries here
ULIBS = -lgameengine -lapphelper -lprimeframework 

# List the linker script for the project
LDSCRIPT = ../../lpc1768_flash.ld

FULL_TARGET_OUT = $(TARGET_OUT_DIR)/$(TARGET_NAME)

ifeq ($(PRIME_DEBUG),1)

OBJDIR	= $(OBJ_PATH)/Debug
TARGET_OUT_DIR	=	$(TARGET_OUT_PATH)/Debug/
UDEFS		=	-DMCU_CHIP_lpc1768 -DPRIME_DEBUG 
ULIBDIR		=	../../Library/PrimeFramework/Debug		\
				../../Library/AppHelper/Debug				\
				../../Library/GameEngine/Debug
				
ASFLAGS = $(MCFLAGS) -g -gdwarf-2 -Wa,-amhls=$(<:.s=.lst)
CPFLAGS = $(MCFLAGS) $(OPT) -gdwarf-2 -mthumb -fomit-frame-pointer -Wall -Wno-cpp -fverbose-asm -Wa,-ahlms=$(<:.c=.lst) $(C_COMPILER_STD) $(DEFS)

else

OBJDIR		=	$(OBJ_PATH)/Release
TARGET_OUT_DIR	=	$(TARGET_OUT_PATH)/Release
UDEFS		=	-D MCU_CHIP_lpc1768
ULIBDIR		=	../../Library/PrimeFramework/Release		\
				../../Library/AppHelper/Release			\
				../../Library/GameEngine/Release
				
ASFLAGS = $(MCFLAGS) -Wa,-amhls=$(<:.s=.lst)
CPFLAGS = $(MCFLAGS) $(OPT) -mthumb -fomit-frame-pointer -Wall -Wno-cpp -fverbose-asm -Wa,-ahlms=$(<:.c=.lst) $(DEFS)

endif

INCDIR	= $(patsubst %,-I%,$(UINCDIR))
LIBDIR	= $(patsubst %,-L%,$(ULIBDIR))
OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRC)))
LIBS	= $(ULIBS)
LDFLAGS	= $(MCFLAGS) -mthumb -u _printf_float --specs=nano.specs --specs=nosys.specs -nostartfiles -T$(LDSCRIPT) -Wl,-Map=$(FULL_TARGET_OUT).map,--cref,--no-warn-mismatch $(LIBDIR) 

# Generate dependency information
CPFLAGS += -MD -MP -MF .dep/$(@F).d

DEFS = $(UDEFS)

#
# makefile rules
#
.PHONY: all
all: echo makedir $(OBJS) $(FULL_TARGET_OUT).elf $(FULL_TARGET_OUT).hex

echo:
		@echo $(OBJS)
		@echo $(OBJDIR)
		@echo $(LIBDIR)
		@echo $(INCDIR)
		@echo $(ULIBS)

makedir:
	mkdir -p $(OBJDIR)
	mkdir -p $(TARGET_OUT_DIR)

$(OBJDIR)/%.o : %.c
	$(CC) -c $(CPFLAGS) -I . $(INCDIR) $< -o $@

$(OBJDIR)/%.o : %.s
	$(AS) -c $(ASFLAGS) $< -o $@

%.elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $@
	$(FILESIZE) $@

%.hex: %.elf
	$(HEX) $< $@

%.bin: %.elf
	$(BIN) $< $@


.PHONY: clean	
clean:
	-rm -rf $(OBJDIR)
	-rm -rf $(FULL_TARGET_OUT).map
	-rm -rf $(FULL_TARGET_OUT).elf
	-rm -rf $(FULL_TARGET_OUT).hex
	-rm -rf $(TARGET_OUT_DIR)
	-rm -f $(SRC:.c=.lst)
	-rm -f $(ASRC:.s=.s.bak)
	-rm -f $(ASRC:.s=.lst)
	-rm -fR .dep

# 
# Include the dependency files, should be the last of the makefile
#
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

# *** EOF ***
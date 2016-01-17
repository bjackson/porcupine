CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

ODIR = obj

# This generates the list of source files
SRC =  $(wildcard *.S) $(wildcard *.c) $(wildcard **/*.S) $(wildcard **/*.c)

# This generates the list of .o files. The order matters, boot.o must be first
OBJS  = boot.o
OBJS += $(filter-out boot.o,$(patsubst %.S,%.o,$(filter %.S,$(SRC))))
OBJS += $(patsubst %.c,%.o,$(filter %.c,$(SRC)))

CPPFLAGS = -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostdinc -g

create-image:
	${OBJCOPY} kernel.elf -O binary kernel.img


Makefile.dep: $(SRC)
	$(CC) -MM $(CPPFLAGS) $(SRC) > $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

ifneq ($(MAKECMDGOALS),dep)
ifneq ($(MAKECMDGOALS),clean)
include Makefile.dep
endif
endif

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

ODIR = obj

# This generates the list of source files
SRC =  $(wildcard *.S) $(wildcard *.c) $(wildcard **/*.S) $(wildcard **/*.c)

# This generates the list of .o files. The order matters, kmain.o must be first
OBJS  = boot.o
OBJS += $(filter-out boot.o,$(patsubst %.S,%.o,$(filter %.S,$(SRC))))
OBJS += $(filter-out boot.o,$(patsubst %.c,%.o,$(filter %.c,$(SRC))))

#If you have any .h files in another directory, add -I<dir> to this line
CPPFLAGS +=-nostdinc -g

CFLAGS = -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostdinc -g
LDFLAGS += -nostartfiles -static

bootimg: Makefile $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -Ttext=0x8000 -o bootimg
	$(OBJCOPY) bootimg -O binary kernel.img

dep: Makefile.dep

Makefile.dep: $(SRC)
	$(CC) -MM $(CPPFLAGS) $(SRC) > $@

run-qemu:
	qemu-system-arm \
	-kernel ./kernel.img \
	-m 256 \
	-M versatilepb \
	-cpu arm1176 \
	-m 256

.PHONY: clean
clean:
	rm -f *.o Makefile.dep bootimg

ifneq ($(MAKECMDGOALS),dep)
ifneq ($(MAKECMDGOALS),clean)
include Makefile.dep
endif
endif

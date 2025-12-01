
TARGET = i686-linux-gnu
CC = $(TARGET)-gcc
CXX = $(TARGET)-g++
AS = $(TARGET)-as
LD = $(TARGET)-ld

SRCDIR        = source
INCDIR        = include
X86DIR        = source/x86
SIMPLEOSDIR   = source/SimpleOS
X86SIMPLEOSDIR= source/x86/SimpleOS

CFLAGS = -ffreestanding -O2 -Wall -Wextra
CXXFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
CXXFLAGS += -I$(INCDIR) -I$(SRCDIR) -I$(X86DIR) -I$(X86SIMPLEOSDIR)

ASFLAGS = --32

OBJS = boot.o X86Main.o Kernel.o Console_x86.o

KERNEL = myos.bin

.PHONY: all clean run

all: $(KERNEL)

$(KERNEL): $(OBJS)
	$(LD) $(OBJS) -T $(X86DIR)/linker.ld -o $@

boot.o: $(X86DIR)/boot.asm
	$(AS) $(ASFLAGS) $< -o $@

X86Main.o: X86Main.cpp $(SIMPLEOSDIR)/Kernel.hpp $(X86SIMPLEOSDIR)/ExtNew.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Kernel.o: $(SIMPLEOSDIR)/Kernel.cpp $(SIMPLEOSDIR)/Kernel.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Console_x86.o: $(X86SIMPLEOSDIR)/Console.cpp $(X86SIMPLEOSDIR)/Console.hpp $(X86SIMPLEOSDIR)/ExtNew.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(KERNEL) *.o

run: $(KERNEL)
	qemu-system-i386 -kernel $(KERNEL)

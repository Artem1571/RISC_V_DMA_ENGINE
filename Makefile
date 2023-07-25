CC = riscv64-unknown-elf-gcc
CFLAGS = -g -mcmodel=medany -mabi=lp64 
AS = riscv64-unknown-elf-as 
ASFLAGS = -g -mabi=lp64
LD = riscv64-unknown-elf-ld
LDFLAGS =  -Tlinker.ld

OBJECTS = start.o main.o uart.o dma.o
TARGET = check_pattern.elf

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(ASFLAGS) -c $< -o $@

clean:
	del /f *.o *.elf
	
run:
	qemu-system-riscv64 -machine sifive_u -kernel $(TARGET) -bios none -serial stdio -display none
	


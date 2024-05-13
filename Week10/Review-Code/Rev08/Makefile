# Sets the microcontroller; This is the one used in the
# circuit playground.  To use a different controller,
# pins_arduino.h in this directory may need to be replaced.

MCU=atmega32u4

RUN_AVR=simavr

PROGS= factorial_driver frame math data_memory_write

all: clean $(PROGS)

factorial_driver: factorial_driver.S factorial.S support.S serial.c 
	avr-gcc -g -mmcu=$(MCU) $^ -o $@

# The following rule takes a .S file, assembles it, and
# links it with a compiled serial.c, which gives printf /
# putchar somemplace to go.
%: %.S 
	avr-gcc -g -mmcu=$(MCU) $< serial.c -o $@

# The .run rule starts a simulator and executes the instructions.  
# If the code does not end with "cli\n sleep", the simulator 
# will continue to execute the code.  The library wrapper has 
# an infinite loop that would otherwise execute after main().
%.run: %
	$(RUN_AVR) --mcu $(MCU) $*

# The .gdb rule starts a simulator and runs the avr-gdb debugger 
%.gdb: %
	@echo ensuring that gdb does not complain about the local .gdbinit file
	grep `pwd` ~/.gdbinit || echo "add-auto-load-safe-path " `pwd` >> ~/.gdbinit
	$(RUN_AVR) --mcu $(MCU) -g $* & avr-gdb $*

clean:
	rm -f $(PROGS) a.out

help:
	@echo "'make all' to clean and assemble all examples"
	@echo "'make prog_name' to assemble a program"
	@echo "'make prog_name.run' to run program prog_name in the simulator"
	@echo "'make prog_name.gdb' to run program prog_name using simulator & gdb"


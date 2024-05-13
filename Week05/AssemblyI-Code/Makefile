# Sets the microcontroller; This is the one used in the
# circuit playground.  To use a different controller,
# pins_arduino.h in this directory may need to be replaced.

MCU=atmega32u4

RUN_AVR=simavr

PROGS=assembly_prog_org

all: clean $(PROGS)

# The following rule takes a .S file, assembles it, and
# links it with a compiled serial.c, which gives printf /
# putchar some place to go.
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
	@echo "adding add-auto-load-safe-path .gdbinit to ~/.gdbinit configuration file"
	grep "add-auto-load-safe-path .gdbinit" ~/.gdbinit || echo "add-auto-load-safe-path .gdbinit" >> ~/.gdbinit
	$(RUN_AVR) --mcu $(MCU) -g $* & avr-gdb $*

clean:
	rm -f $(PROGS) a.out

help:
	@echo "'make all' to clean and assemble all examples"
	@echo "'make prog_name' to assemble a program named prog_name"
	@echo "'make prog_name.run' to run program prog_name in the simulator"
	@echo "'make prog_name.gdb' to run program prog_name using simulator & gdb"


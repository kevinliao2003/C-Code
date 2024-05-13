# Sets the microcontroller; This is the one used in the
# circuit playground.  To use a different controller,
# pins_arduino.h in this directory may need to be replaced.

MCU=atmega32u4

RUN_AVR=simavr

PROGS= do_while while pointer_register_read1 pointer_register_read2 \
       pointer_register_write array_sum \
       double_value_single_file double_value_driver c_prog_calling_double_value_s

all: $(PROGS)

double_value_driver: double_value_driver.S double_value.S support.S serial.c
	avr-gcc -g -mmcu=$(MCU) $^ -o $@

c_prog_calling_double_value_s: double_value.S c_prog_calling_double_value.c serial.c
	avr-gcc -g -mmcu=$(MCU) $^ -o $@

c_prog_calling_double_value:
	clear
	@echo "wrong target: use c_prog_calling_double_value_s (notice the_s at the end)"


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
	@echo "adding add-auto-load-safe-path .gdbinit to ~/.gdbinit configuration file"
	grep "add-auto-load-safe-path .gdbinit" ~/.gdbinit || echo "add-auto-load-safe-path .gdbinit" >> ~/.gdbinit
	$(RUN_AVR) --mcu $(MCU) -g $* & avr-gdb $*

clean:
	rm -f $(PROGS) a.out

help:
	@echo "'make all' to clean and assemble all examples"
	@echo "'make prog_name' to assemble a program"
	@echo "'make prog_name.run' to run program prog_name in the simulator"
	@echo "'make prog_name.gdb' to run program prog_name using simulator & gdb"


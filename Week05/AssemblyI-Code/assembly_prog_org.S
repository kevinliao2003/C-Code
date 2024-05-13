;;; Organization of typical avr program (semicolon  used for comments (don't use #))

;;; Symbolic constants 
        .set LETTER_A, 65      ; Symbolic constant for letter A
        .set NEWLINE, 10       ; Symbolic constant for newline

;;; Global data
        .data                  ; Directive that starts data section.
x:      .byte 6                ; x is a label and represents the
                               ; location of the value 6

;;; Program code
        .text                  ; Directive that starts code section

.global main                   ; Makes main label externally available
main:                          
        ;; main function. This function prints letter A
        ;; followed by newline character.  We need the 
        ;; newline to force the flushing of character A.  

        call init_serial_stdio ; To call a function we use the call instruction
                               ; init_serial_stdio allow us to do input/output

                               ; To print a letter we need to set registers 
                               ; r25 (high byte) and r24 (low bytes). The 
                               ; pair r25:r24 represent the value to print
                               ; gcc dictates we use these registers

        ldi r24, LETTER_A      ; The ldi instruction loads a value into a register.
        clr r25                ; Sets high byte of putchar's integer argument to 0.
        call putchar           ; Calls putchar to print the character
        
	ldi r24, NEWLINE       ; Initializes r24 with '\n' character ascii value
        clr r25                ; Sets high byte of putchar's integer argument to 0
	call putchar 

	cli                    ; We need to stop the program. Relying on cli and sleep. 
        sleep                          

        ret                    ; Adding this ret to show functions end with ret
                               ; but this ret is unreachable (program already stopped)

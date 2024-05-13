;;; Example - exploring returning values from functions 

        .data
pctd:
        .asciz "%d "            ; defines a string (nul terminated) 

        .text                 

.global main                  
main:                          
        ;; Not following caller-save as we don't care if registers are modified
        call init_serial_stdio 

        call returns_5_as_uint8 ; leaves answer in r25:24 that pint relies on
        call pint 

        ; to see output we need a newline (not saving r24 and r25)
        ldi r24, 10 
        clr r25
        call putchar

        cli                     ; Stopping program
        sleep                          

        ret                    

.global returns_5_as_uint8
returns_5_as_uint8:
        ;; returns 5 as unsigned 8-bit value
        ldi r24, 5
        clr r25
        ret	

.global returns_8_as_uint32
returns_8_as_uint32:
        ;; returns 8 as unsigned 32-bit value
        ldi r22, 8
        clr r23
        clr r24
        clr r25
        ret

.global pint
pint:
        ;; Prints an integer value, r22/r23 have the format string
        ldi r22, lo8(pctd)      ; lower byte of the string address
        ldi r23, hi8(pctd)      ; higher byte of the string address
        push r25
        push r24
        push r23
        push r22
        call printf
        pop r22
        pop r23
        pop r24
        pop r25

        ret


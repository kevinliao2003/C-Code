;;; Example - reading values from memory using X pointer register.
;;;           Program prints values 15 15 16

        .data
pctd:
        .asciz "%d\n"           ; Changed format string to add \n  

values:                         ; A label is an address; values is
	.byte 15                ; the address of 15 in memory, but
	.byte 16                ; can also be see it as the address
	.byte 17                ; of the array that starts at 15
	.byte 18

        .text                 

.global main                  
main:                          
        call init_serial_stdio 

        lds r24, values         ; Reading the first value (r24 = *values, 
                                ; using lds)
        clr r25
        call pint               ; Printing the value

        ldi r26, lo8(values)    ; Initializing X register with address of values
        ldi r27, hi8(values)    ; lo8(values) least significant address byte (LSB)
                                ; hi8(values) most significant address byte (MSB)

        ld  r24, X              ; Using ld (NOT lds); r24 = *value
        clr r25

        push r26                ; Saving X (caller-save) before calling pint
        push r27                
        call pint               ; Printing the value
        pop r27                 ; Restoring registers (X is restored)
        pop r26

        adiw r26, 1             ; Moving to the next byte (Try 2, 3)
        ld  r24, X              ; Using ld (NOT lds); r24 = *(values + 1)
        clr r25

        call pint               ; Printing the value

        cli                     ; Stopping program
        sleep                          

        ret                    

;;; Not defining it global as we will use it just in this file
pint:
        ;; Prints an integer value, r22/r23 have the format string
        ldi r22, lo8(pctd)      ; Lower byte of the string address
        ldi r23, hi8(pctd)      ; Higher byte of the string address
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


;;; Example - prints values 1 to 5 (do while)

;;; Global data
	.data
pctd:
        .asciz "%d "         

upper_limit: .byte 0x5              

;;; Program code
        .text                 

.global main                  
main:                          
        call init_serial_stdio

        call print_numbers

	cli                    ; Stopping program
        sleep                          

        ret                    

;;; Not defining it global as we will use it just in this file
print_numbers:
        push r16               ; Practicing callee-save (we could have
        push r17               ; use other registers and avoid calle-save
                               ; process)

        ldi r16, 1             ; Initialing r16 ("iteration variable")
        lds r17, upper_limit   ; Upper limit

1:      mov r24, r16           ; Printing value
        clr r25                
        call pint

        inc r16                ; Increasing iteration variable 
        cp r17, r16	       ; We don't have a <= instruction. We  
                               ; phrase the comparison using brsh (unsigned).
        brsh 1b                ; We go back as long as r17 >= r16

        clr r25                ; Newline
        ldi r24, 10            
        call putchar
	
        pop r17                ; Restoring callee-save registers
        pop r16

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


;;; Example - examining the value of SREG using gdb info registers
;;; Set a break point after addition and inspect SREG; repeat
;;; the process after subtraction

        .data
pctd:
        .asciz "%d "            

val1:   .byte 10       
val2:   .byte 20       

        .text                 

.global main                  
main:                          
        call init_serial_stdio  

        ldi r24, 10            
        ldi r19, 20
        add r24, r19            ; Adding (examine SREG register after add) (30)
        clr r25           
        call pint               ; Printing

        ldi r24, 40            
        ldi r19, 40
        sub r24, r19            ; Subtracting (examine SREG register after sub) (0)
        clr r25
        call pint               ; Printing

        ldi r24, 10             ; Newline
        clr r25
        call putchar

        cli                     ; Stopping program  
        sleep                          

        ret                    

;;; pint
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


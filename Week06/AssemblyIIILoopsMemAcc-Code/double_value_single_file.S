;;; Example - reads value from memory and doubles it
;;; Prints 30

;;; Symbolic Constants
        .data
pctd:
        .asciz "%d "            ; Format string  

value:                          ; A label is an address; value is
	.byte 15                ; the address of 15 in memory

        .text                 

.global main                  
main:                          
        call init_serial_stdio 

        lds r18, value          ; Loading value to double
        clr r25                 ; Setting argument for double_value function
        mov r24, r18            ; We must use r25 and r24
        
        call double_value       ; Calling the function.  Function will leave
                                ; result in r25:r24.  This is what pint needs
        call pint               ; Printing the value
        call prt_newline        

        cli                     ; Stopping program
        sleep                          

        ret                    

;;; double_value
	.global double_value    
double_value: 
              add r24, r24
              clr r25          
              ret              ; Always add ret first so you don't forget
                               
;;; pint
	.global pint
pint:
        ;; prints an integer value, r22/r23 have the format string
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
 
;;; prt_newline
	.global prt_newline
prt_newline:
        clr r25           ; To use putchar we place
        ldi r24, 10       ; the value to print in r25:r24
        call putchar

        ret


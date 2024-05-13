;;; Example - reading (from memory) and printing integer

;;; Symbolic Constants
        .set NEWLINE, 10

        .data
pctd:
        .asciz "%d "            ; Format string  

value:                          ; A label is an address; value is
	.byte 15                ; the address of 15 in memory

        .text                 

.global main                  
main:                          
        call init_serial_stdio 

        lds r24, value          ; Reading the first value. Using
                                ; r24 as we will call the function
                                ; pint that has one parameter
        push r24                ; Saving value in the stack as we 
                                ; want to use this value later on. 
                                ; Calling the function may modify 
                                ; this register
        clr r25                 ; Our value fits in one byte so
                                ; we don't need the high byte
        call pint               ; Printing the value
        call prt_newline        

        pop r24                 ; Retrieving value from stack
        inc r24                 ; Incrementing value
        clr r25                 ; Making sure r25 is 0
        call pint               ; Printing the incremented value
        call prt_newline        

        cli                     ; Stopping program
        sleep                          

        ret                    

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
 
prt_newline:
        clr r25                ; To use putchar we place
        ldi r24, NEWLINE       ; the value to print in r25:r24
        call putchar

        ret


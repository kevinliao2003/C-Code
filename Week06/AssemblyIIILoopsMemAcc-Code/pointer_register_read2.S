;;; Example - reading from memory using X+ (values printed are 15 and 16)

        .data
pctd:
        .asciz "%d\n"           ; Adding \n to format string    

values:                        
	.byte 15            
	.byte 16
	.byte 17
	.byte 18

        .text                 

.global main                  
main:                          
        call init_serial_stdio  

        ldi r26, lo8(values)    ; Reading first value using X (r27:r26)
        ldi r27, hi8(values)    ; r27:r26 = values
        ld  r24, X+             ; Using X+ (increases pointer by one byte)
        push r26                ; Saving X (caller-save) before printing
        push r27                ; What role does push serve?
        clr r25                 
        call pint               ; Printing the value
        pop r27                 ; Restoring X pointer register
        pop r26

        ld r24, X               ; Printing the second value using incremented X
                                ; Not saving r26, r27; don't care at this 
                                ; point if they are overwritten
        clr r25
        call pint               ; Printing value

        cli                     ; Stopping program  
        sleep                          

        ret                     ; 15 16

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


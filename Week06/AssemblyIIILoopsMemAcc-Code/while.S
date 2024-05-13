;;; Example - prints values 1 to 5 (while)

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

        push r16               ; Callee-save 
        push r17               

        ldi r16, 1             ; Loop starts, r16 "iteration variable" (ldi - load immediate)
        lds r17, upper_limit   ; Upper limit
        cp r17, r16	       ; Checking if we are done. We don't have
        brlo 1f                ; greater than instruction. We need to phrase
                               ; comparison using brlo

2:      mov r24, r16           ; Printing value
        clr r25                ; r25 cleared
        call pint              ; the value is printed

        inc r16                ; Increasing "iteration variable"
        cp r17, r16	       ; Checking whether we reach limit
        brsh 2b;               ; while loop condition

        clr r25                ; Newline
        ldi r24, 10            
        call putchar
	
1:      pop r17                ; Restoring registers 
        pop r16

        ret                    

;;; Not defining it global as we will use it just in this file
pint:
        ;; prints an integer value, r22/r23 have the format string
        ldi r22, lo8(pctd)     ; Lower byte of the string address
        ldi r23, hi8(pctd)     ; Higher byte of the string address
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


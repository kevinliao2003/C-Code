;;; Example - Prints compares two registers and a register and a constant 

;;; Symbolic constants
	.set LETTER_N, 'N'
	.set LETTER_Y, 'Y'
        .set NEWLINE, 10 

;;; Program code
        .text                 

.global main                  
main:                          
        call init_serial_stdio

        ldi r18, 6             ; Comparing two registers
        ldi r19, 5             ; 
        cp r18, r19            ; Comparing registers (r18 - r19)
        breq 1f                ; If equal jump to 1 (target): f represents forward
	ldi  r24, LETTER_N     ; Store N
        jmp 2f
1:	ldi r24, LETTER_Y      ; Store Y

2: 	clr r25                ; Printing result (r25:r24)
	call putchar          
        call prt_newline

        ldi r18, 79 
        cpi r18, 78            ; Comparing register and constant
        brlo 1f                 ; if 79 < 78
        ldi r24, LETTER_N
        jmp 2f
1:      ldi r24, LETTER_Y
          
2:      clr r25
        call putchar
        call prt_newline

	cli                    ; Stopping program
        sleep                          

        ret                    

;;; prt_newline
        .global prt_newline
prt_newline:
        clr r25                ; To use putchar we place
        ldi r24, NEWLINE       ; the value to print in r25:r24
        call putchar

        ret


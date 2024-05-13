;;; Support functions pint and prt_newline.  
;;; Assemble along with code that uses the functions.

    .data                       ; We need .data 
pctd:
        .asciz "%d "            ; Format string

    .text

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


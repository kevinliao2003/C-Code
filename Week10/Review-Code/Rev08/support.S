;;; Provides support functions

.text 
.global prt_newline
prt_newline:                   ; no need for global directive
        clr r25
        ldi r24, 10
        call putchar
        
        ret

.global pintv2
pintv2:
        ;; prints an integer value, r23:r22 must have the format string
        ;; and it has been initialized by the caller
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


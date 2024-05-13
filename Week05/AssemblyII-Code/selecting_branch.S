;;; Example - Illustrates we must chose correct branch based 
;;;           on whether we are treating data as signed or unsigned

;;; Symbolic Constants
	.set NEWLINE, 10

;;; Global data
        .data                 

pctd:   .asciz "smaller is 0x%02x"           ; defines a string (nul terminated)
a:      .byte 11
b:      .byte 127                            ; Try 20, 127, 128

;;; Program code
        .text                 

.global main                  
main:                          
        call init_serial_stdio

        call correct
        call incorrect

	cli                    ; Stopping program
        sleep                          

        ret                    

;;; not defining the following as .global as we are using the locally
correct: 
        ;; Using correct branch instruction
        lds r18, a
        lds r19, b
        cp r18, r19
        brlo 1f         ; less than comparison
        mov r24, r19
        jmp 2f
1:      clr r25
        mov r24, r18
2:      call pint
        call prt_newline
        ret

incorrect: 
        ;; Using incorrect branch instruction
        lds r18, a
        lds r19, b
        cp r18, r19
        brlt 1f
        mov r24, r19
        jmp 2f
1:      clr r25
        mov r24, r18
2:      call pint
        call prt_newline
        ret

;;; prt_newline
        .global prt_newline
prt_newline:
        clr r25                ; To use putchar we place
        ldi r24, NEWLINE       ; the value to print in r25:r24
        call putchar

        ret

;;; pint
        .global pint
pint:
        ;; Prints an integer value, r22/r23 have the format string
        ldi r22, lo8(pctd)     ; lower byte of the string address
        ldi r23, hi8(pctd)     ; higher byte of the string address
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


;;; Example - writes the values 77 and 99 to memory using sts and st; 
;;; Also using X, Y, Z register pointers

        .data
pctd:
        .asciz "%d "

values: ; represents data memory area where we will write
        ; note we are not using any .byte directive

        .text

.global main
main:
        call init_serial_stdio

        push r29                ; needs to save r29,r28 (callee-saved)
        push r28

        ldi r18, 77
        sts values, r18         ; assigning 77 to location values (using sts)

        ldi r28, lo8(values)    ; reading first value using Y (r29:r28)
        ldi r29, hi8(values)    ; r29:r28 = values
        ld  r24, Y+             ; using Y+ (increases pointer by one location)
        clr r25                 ; printing the value
        call pint

        ldi r18, 99             ; writing location after first entry
        st Y, r18               ; using st (NOT sts)
        ldi r30, lo8(values)    ; using Z pointer register to read value written
        ldi r31, hi8(values)    
        adiw r30, 1             ; moving forward Z pointer one position
        ld r24, Z               ; reading value written

        clr r25                 ; printing value
        call pint

        clr r25                 ; newline
        ldi r24, 0xa
        call putchar

        pop r28
        pop r29

        cli                     ; stopping program
        sleep

        ret

pint:
        ;; prints an integer value, r22/r23 have the format string
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


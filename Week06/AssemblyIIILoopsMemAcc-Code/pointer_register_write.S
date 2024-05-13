;;; Example - writes the values 77 and 99 to memory using sts and st; 
;;; Also using X, Y, Z pointer registers

        .data
pctd:
        .asciz "%d\n"           ; Adding \n to format string

values: ; Represents data memory area where we will write
        ; We don't need to use .byte

        .text

.global main
main:
        call init_serial_stdio

        call write_values

        cli                     ; Stopping program
        sleep

        ret

write_values:

        push r29                ; Needs to save r29,r28 (callee-saved)
        push r28                ; We are planning on using Y pointer register

        ldi r18, 77             ; Assigning 77 to location "values" (using sts)
        sts values, r18         

        ldi r28, lo8(values)    ; Initializing Y pointer register
        ldi r29, hi8(values)    ; r29:r28 = values
        ld  r24, Y+             ; Reading *values using Y+ (increases pointer)
        clr r25                 ; Printing the value read
        call pint

        ldi r18, 99             ; Writing 99 to location after first entry (77)
        st Y, r18               ; Using st (NOT sts).  Y points to location

        ldi r30, lo8(values)    ; Using Z pointer register to read value written
        ldi r31, hi8(values)    ; Initializing Z to values

        adiw r30, 1             ; Moving forward Z register pointer one byte
        ld r24, Z               ; Reading *(values + 1)

        clr r25                 ; Printing value
        call pint

        pop r28                 ; Restoring (callee-saved)
        pop r29

        ret                     ; 77 99

;;; Not defining it global as we will use it just in this file
pint:
        ;; Prints an integer value, r22/r23 have the format string
        ldi r22, lo8(pctd)      ; Lower byte of thg string address
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


;;; Example - Illustrates how to use mul (unsigned multiply)

;;; Global data

        .data                 

pctd:   .asciz "%d "          ; defines a string (nul terminated)
a:      .byte 200
b:      .byte 150

;;; Program code
        .text                 

.global main                  
main:                          
        call init_serial_stdio

        clr r25
        lds r18, a             ; reading value for a
        lds r24, b             ; reading value for b
        add r24, r18           ; just using add is wrong for 200 and 150
        adc r25, r25           ; we need adc
        push r24               ; caller save
        push r25
        call pint
        call prt_newline
        pop r25                ; restoring caller save
        pop r24 

        adiw r24, 5            ; adds five to previous result (r25:r24 is updated) 
        call pint
        call prt_newline
         
        ldi r24, 8             ; multiplication
        ldi r25, 6 
        mul r24, r25           ; result in r1:r0
        movw r24, r0           ; copies r1:r0 to r25:r24
        clr r1                 ; we should always make sure is back to 0 

        call pint              ; printing multiplication result
        call prt_newline

        ldi r24, 32            ; multiplying by 2
        lsl r24 
        call pint
        call prt_newline

        ; next example shows we need to use brlo with unsigned
        ldi r24, 2             ; comparison between r24 and 11
        cpi r24, 11            ; the smaller will be printed
        brlt 1f                ; try r24 with 5, 199 (fails)
        ldi r24, 11            
1:      call pint
        call prt_newline

	cli                    ; stopping program
        sleep                          

        ret                    

prt_newline:                   
        ;; prints new line
        clr r25
        ldi r24, 10
        call putchar

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


;;; Example - illustrates some fundamental instructions.

;;; Symbolic Constants
	.set NEWLINE, 10

;;; Global data
        .data                 
a:      .byte 0x41            ; Could have used 65 (decimal), 0b01000001 (binary)

;;; Program code
        .text                 

.global main                  
main:                          
        call init_serial_stdio

        call prt_newline       ; Printing \n\n\n (3 blank lines)
        call prt_newline        
        call prt_newline
        call prt_char          ; Printing char at memory location a
        call prt_char          ; Printing char at memory location a
        call prt_char          ; Printing char at memory location a

	cli                    ; Stopping the program
        sleep                          

        ret                    

;;; prt_newline
	.global prt_newline
prt_newline:
        clr r25                ; To use putchar we place
        ldi r24, NEWLINE       ; the value to print in r25:r24
        call putchar       
  
        ret

;;; ptr_char
	.global prt_char
prt_char:
        lds r18, a             ; Reading a from memory  

        clr r25                ; Initializing r25:r24, clears r25
        mov r24, r18           ; Printing, copies r18 to r24
        call putchar       
        call prt_newline       ; Flushing so we can see output

        lds r18, a             ; r18 need to reload as putchar 
                               ; could have written r18
        inc r18                ; Moving to next character, increases value by 1
        sts a, r18             ; Writing to memory (a)
        
        ret



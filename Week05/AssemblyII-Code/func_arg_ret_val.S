;;; Example - Adding two uint8_t and returning uint8_t or uint16_t

;;; Symbolic Constants
        .set NEWLINE, 10

        .data
pctd:
        .asciz "%d "            ; Format string  

value:                          ; A label is an address; value is
	.byte 15                ; the address of 15 in memory

        .text                 

.global main                  
main:                          
        call init_serial_stdio 

        clr r25                       ; First argument
        ldi r24, 10                   
        clr r23                       ; Second argument
        ldi r22, 25             
        call add_uint8_t              ; Will leave results in r25:r24 (35)
        call pint                     ; Printing result. What it needs is in r25:r24
        call prt_newline        

        clr r25                       ; First argument
        ldi r24, 255                  
        clr r23                       ; Second argument
        ldi r22, 1             
        call add_uint8_t_ret_uint16_t ; Will leave results in r25:r24 (256)
        call pint                     ; Printing result. What it needs is in r25:r24
        call prt_newline        

        ldi r24, 255                  ; Using adiw 
        clr r25
        adiw r24, 4                   ; adiw (add immediate to word) adds 4 to r25:r24 (259)
        push r24                      ; r24, r25 are caller save so if I want to 
        push r25                      ; preserve their value I need to save them
        call pint                     
        call prt_newline        
                                      
        pop r25                       ; Using sbiw on result of previous computation
        pop r24                       ; Make sure you pop using correct register
        sbiw r24, 50                  ; sbiw (subtract immediate from word) subtracts 100 (209)
                                      ; from r25:r24
        call pint
        call prt_newline        

        cli                           ; Stopping program
        sleep                          

        ret                    

;;; add_uint8_t
	.global add_uint8_t
add_uint8_t: 
        ;;; Adding two uint8_t and returning uint8_t
        add r24, r22            ; Adding. We only care about lower bytes
        clr r25                 ; r25:r24 has the result

        ret

;;; add_uint8_t_ret_uint16_t
	.global add_uint8_t_ret_uint16_t
add_uint8_t_ret_uint16_t: 
        ;;; Adding two uint8_t and returning uint16_t
        add r24, r22            ; Adding lower bytes
        clr r25                
        adc r25, r25            ; Add with carry
        ret

;;; pint
	.global pint
pint:
        ;;; Prints an integer value, r22/r23 have the format string
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
        clr r25                ; To use putchar we place
        ldi r24, NEWLINE       ; the value to print in r25:r24
        call putchar

        ret


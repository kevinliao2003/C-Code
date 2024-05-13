;;; Example - A function that uses the stack to pass parameters
;;; and defines local variables in the stack. 
;;; Program implements sum_sqrs(a, b) =  a * a + b * b

        .set SPH, 0x3e         ; Stack pointer (high byte)
        .set SPL, 0x3d         ; Stack pointer (low byte)

;;; Global data
        .data                 

pctd:   .asciz "%d "         
a:      .byte 3
b:      .byte 4

;;; Program code
        .text                 

.global main                  
main:                          
        ;; Calls sum_sqrs(3, 4), printing 25 as result
        call init_serial_stdio

        lds r22, a             ; Pushing parameters (a is the first parameter)
        lds r23, b
        push r23               ; Pushing parameters; b goes in first, a, second
        push r22
        call sum_sqrs          
        pop r22                ; Removing parameters    
        pop r23            
        call pint              ; Printing the result left in r25:r24 by sum_sqrs
        call prt_newline

	cli                    ; Stopping program
        sleep                          

        ret                    

sum_sqrs:
        ;; Computes a * a + b * b
                               ; SETTING FRAME 
        push r28               ; Saves old frame/base pointer 
        push r29 
        in r28, SPL            ; Retrieving stack pointer value and initializing Y
        in r29, SPH            ; 
        sbiw r28, 2            ; Allocating space for 2 local variables; a byte each 
        out SPL, r28           ; Adjusting stack pointer for local variables
        out SPH, r29           ; END SETTING FRAME 



        ldd r24, Y+7           ; First parameter (a) 
        mul r24, r24           ; a * a
        mov r24, r0            ; Result in r24 (ignoring r25)
        std Y+1, r24           ; Storing in first local variable 

        ldd r24, Y+8           ; Second parameter (b)
        mul r24, r24           ; b * b
        mov r24, r0            ; Result in 24 (ignoring r25)
        std Y+2, r24           ; Storing in second local variable
                              
        ldd r24, Y+1           ; Accessing first local variable
        ldd r25, Y+2           ; Accessing second local variable
        add r24, r25           ; sum
        clr r1                 ; We must always leave r1 set to  0
        clr r25                ; r25:r24 has the result



                               ; THROWING AWAY FRAME
        adiw r28, 2            ; Throws away locals 
        out SPL, r28           ; Adjusting stack pointer
        out SPH, r29 
        pop r29                ; Restoring old frame / base pointer
        pop r28                ; END THROWING AWAY FRAME 

        ret

pint:
        ;; Prints an integer value, r23:r22 have the format string
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

prt_newline:                
        ;; Prints newline
        clr r25
        ldi r24, 10
        call putchar

        ret


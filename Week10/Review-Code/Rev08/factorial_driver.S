;;; Example - Recursion example (factorial).  This file
;;; represents the driver. This example illustrates how
;;; you could write the project functions by defining a
;;; a driver that will access the functions you need to
;;; implement. To assemble:
;;; avr-gcc -g -mmcu=atmega32u4 factorial_driver.S factorial.S support.S serial.c  
;;; The Makefile rule factorial_recursive will take care of 
;;; creating the executable. 

	.data
msgpctd:
        .asciz "Factorial value is: %d"           ; defines a string (nul terminated)

        .text                 

.global main                  
main:                          
        ;; driver for our program
        call init_serial_stdio

        clr r25                ; setting argument to function
        ldi r24, 5             ; computing factorial of 5 
        call factorial         ; calling the function

        ; using a different version for pint
        ; we need to specify the format string before calling
        ldi r22, lo8(msgpctd)  ; lower byte of the format string address
        ldi r23, hi8(msgpctd)  ; higher byte of the format string address
        call pintv2
        call prt_newline

	cli                    ; stopping program
        sleep                          

        ret                    



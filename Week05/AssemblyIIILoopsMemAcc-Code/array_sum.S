;;; Example - computes the sum of elements in an array "elems"
;;; The printed sum is 150

;;; Global data
	.data

pctd:
        .asciz "%d\n"          ; \n added to format string      

number_elems: .byte 5          ; Number of elements to print 
elems: .byte 10, 20, 30, 40, 50

;;; Program code
        .text                 

.global main                  
main:                          
        call init_serial_stdio

        call print_array_sum

	cli                    ; Stopping program
        sleep                          
        ret

;;; Not defining it global as we will use it just in this file
print_array_sum: 

        push r15               ; Callee-save 
        push r16               
   
        ldi r26, lo8(elems)    ; Initializing X pointer register
        ldi r27, hi8(elems)
         
        clr r18                ; r18 is accumulator (set to 0)
        lds r15, number_elems  ; Setting number of elements to add
        ldi r16, 1             ; Loop starts, r16 iteration variable
        cp r15, r16	       ; Checking whether we reach limit
        brlo 1f                

2:      ld r24, X+             ; Reading value and moving X 
        add r18, r24           ; Adding value to accumulator

        inc r16                ; Increasing "iteration variable"
        cp r15, r16	       ; Checking whether we have added
        brsh 2b;               ; the total number of elems

1:      clr r25                ; Printing sum (r18) 
        mov r24, r18
        call pint
	
        pop r16                ; Restoring registers
        pop r15

        ret                    

;;; Not defining it global as we will use it just in this file
pint:
        ;; prints an integer value, r22/r23 have the format string
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


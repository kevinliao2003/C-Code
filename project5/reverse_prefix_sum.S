;;; Kevin Liao
;;; 117815542
;;; kliao

;;; Implementation that computes the reverse prefix sum.

;;; Symbolic Constants
    .set NEWLINE, 10    ; numeric constant to print out a blank line

;;; Global data
	.data    

pctd:
    .asciz "%d"         ; space added to format string

;;; Program code
    .text

.global reverse_prefix_sum
reverse_prefix_sum:
    mov r27, r25        ; copies arguments to X
    mov r26, r24        ; copies arguments to X

    ;; loops through the array
    ld r18, X           ; loads the current pointer          
    cpi r18, -1         ; checks if -1 has been read
    breq 1f             ; if yes, branch
    ;; else, move onto the next value
    adiw r24, 1

    ;; r18, r26, and r267 are stacked for future reference
    push r18
    push r26
    push r27

    ;; recursive call
    call reverse_prefix_sum
    ;; stores the values (after recursive call) in new registers
    mov r21, r25
    mov r20, r24        

    pop r27
    pop r26
    pop r18

    clr r19             ; clears the higher bit
    add r20, r18        ; sum of the remainder of the array
    adc r21, r10        ; adds carry byte to higher bit

    st X, r20           ; sets the parameter to the sum

    ;; returns the sum of the remainder
    mov r25, r21        
    mov r24, r20        
    ret
1:
    clr r24             ; clears r24
    clr r25             ; clears r25
    ret                 ; returns 0 if the last value was read

.global print_array 
print_array:
    mov r27, r25        ; copies arguments to X
    mov r26, r24        ; copies arguments to X

3:
    ld r19, X+          ; loads the parameter (current pointer) to r19
    cpi r19, -1         ; checks if -1 has been read
    breq 2f             ; if yes, branch

    ld r18, X           ; loads the next integer

    ;; r26 and r27 are pushed onto the stack, because X needs to be preserved
    clr r25
    mov r24, r19        ; moves the integer value to r24
    
    ;; r18, r19, and r27 stacked for future reference
    push r18
    push r26
    push r27
    call pint           ; prints the integer value
    pop r27
    pop r26
    pop r18

    cpi r18, -1         ; checks if the last integer was loaded
    breq 2f             ; if yes, branch

    ;; prints out a space between the integers
    ldi r24, ' '
    call putchar

    jmp 3b              ; continues looping
2:                      
    call prt_newline    ; prints a blank line
    ret                 ; exits the function

pint:
    ;; prints an integer value, r22/r23 have the format string
    ldi r22, lo8(pctd)     ; Lower byte of the string address
    ldi r23, hi8(pctd)     ; Higher byte of the string address
    push r25               ; registers popped onto the stack
    push r24
    push r23
    push r22
    call printf            
    pop r22                ; registers popped off of the stack
    pop r23
    pop r24
    pop r25

    ret

prt_newline:
    clr r25                ; To use putchar we place
    ldi r24, NEWLINE       ; the value to print in r25:r24
    call putchar           ; prints out blank line

    ret
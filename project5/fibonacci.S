;;; Kevin Liao
;;; 117815542
;;; kliao

;;; Implementation that computes the nth fibonacci number.

    .global fib                 
fib:  
    ;; r25 must be checked first, since it is the higher bit
    ;; r25 and r24 are compared, since a 16 bit number is passed in
    ;; if either r25 and r24 is 0 or 1, branch

    ;; checks if r25 is 0 or 1
    cpi r25, 0      ; checks if upper bit is 0
    breq 4f         ; branches if the upper bit is 0
    cpi r25, 1      ; checks if upper bit is 1
    breq 4f         ; branches if the upper bit is 1

4:  
    ;; checks if r24 is 0 or 1
    cpi r24, 0      ; checks if lower bit is 0
    breq 1f         ; branches if the lower bit is 0
    cpi r24, 1      ; checks if lower bit is 1
    breq 1f         ; branches if the lower bit is 1
    
    ;; recursive calls are needed for numbers other than 0 and 1
    ;; I have to split the recursion into separate if statements.

    sbiw r24, 1     ; subtracts 1 from the register - performs recursion for fib(n - 1)

    ;; r24 and r25 pushed onto stack for use after recursive call
    push r24                    
    push r25                    

    call fib        ; recursive fib call      

    ;; saves the values (after recursive call) in new registers
    mov r26, r24                
    mov r27, r25

    ;; registers popped in reverse order
    pop r25                     
    pop r24

    sbiw r24, 1     ; subtracts 1 from the register - performs recursion for fib(n - 1)      

    ;; r24, r25, r26, and r27 pushed onto stack for future use
    push r24                    
    push r25                    
    push r26                    
    push r27                    

    call fib        ; recursive fib call       

    ;; saves the values (after recursive call) in new registers
    mov r18, r24                
    mov r19, r25

    ;; registers popped in reverse order
    pop r27                     
    pop r26
    pop r25                     
    pop r24

    adc r18, r26    ; adds the lower bits
    adc r19, r27    ; adds the higher bits

    ;; saves the sum in the r25 and r24 registers, which are returned
    mov r24, r18                
    mov r25, r19
1: 
    ret             ; if n is 0 or 1

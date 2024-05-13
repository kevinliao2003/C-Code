;;; Kevin Liao
;;; 117815542
;;; kliao

;;; Implementation that computes the square root of an integer.

    .global isqrt                 
isqrt:
    mov r18, r24                  ; r18 represents the number passed in by parameter
    cpi r18, 2                    ; compares the number to 2
    brlo 2f                       ; if the number is less than 2, it is returned

    ;; shifts the number right by 2
    lsr r24                       
    lsr r24                      
    
    ;; the number is stacked for future reference
    push r18
    call isqrt                    ; isqrt recursive call
    pop r18

    lsl r24                       ; shifts the number (after recursive call) left by 1
    mov r19, r24                  ; r19 stores the small value
    mov r26, r19                  ; r26 stores the large value

    ;; adds 1 to to the large value (r26)
    inc r26                       

    ;; mul saves the register into r1 (higher bit) and r0 (lower bit)
    mul r26, r26                  ; squares the large value
    mov r23, r0                   ; saves the product to a new register (r23)
    clr r1                        ; clears the higher bit
    
    cp r18, r23                   ; compares the parameter to the large value
    brlo 1f                       ; if less than, returns small value

    mov r24, r26                  ; else, returns large value
    ret
1:
    mov r24, r19                  ; returns small value
    ret
2:
    mov r24, r18                  ; returns the number less than 2
    ret                          
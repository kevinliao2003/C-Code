
;;; Five
    .global Five
Five:   
    ;;; uint16_t Five(): return 5 as a uint16_t
    ldi r24, 5      ; load immediate
    clr r25         ; clears the upper bit
    ret             ; return

;;; Max
    .global Max
Max:
    ;;; uint8_t max(uint8_t x, uint8_t y): return the greater of the arguments
    cp r24, r22         ; compare x (passed in as r24) to y (passed in as r22)
    brsh 1f             ; if x >= y, branch 1f
    mov r24, r22        ; copies y into return value / first param slot
    clr 25              ; clears r25 for 8 bit arguments
1:
    ret
    
;;; Strlen
    .global Strlen
Strlen:
    ;;; uint16_t Strlen(char *arg)
    mov r27, r25    ; loads r25 into r27 (copies argument to X)
    mov r26, r24    ; loads r24 into r26 (copies argument to X)

    ;; clears r24 and r25, because the return value is 16 bits
    clr r25         ; initializes return value to zero
    clr r24
2:  
    ld r23, X+      ; increments register by 1
    cpi r23, 0      ; 0 equivalent to NULL in C
    breq 1f         ; if loaded value was zero, branch 1f (label 1, forward)
    adiw r24, 1     ; increments return value (MUST USE ADIW AS OPPOSED TO INC)
    jmp 2b          ; label 2, backward
1:
    ret


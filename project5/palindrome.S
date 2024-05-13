;;; Kevin Liao
;;; 117815542
;;; kliao

;;; Implementation that determines whether a string is a palindrome.

    .global is_palindrome                 
is_palindrome:
    mov r31, r25            ; copies argument to Z
    mov r30, r24            ; copies argument to Z
    mov r27, r25            ; copies argument to X
    mov r26, r24            ; copies argument to X

    ;; the following registers are stacked for future reference
    push r15                ; r15 stores the string length
    push r16                ; r16 is a pointer to the last char
    push r17                ; r17 is a pointer to the front char
    push r28                ; r28 is an iteration variable
    push r30
    push r31

    call Strlen             ; determines the length of the string parameter
    mov r15, r24            ; string length copied

    pop r31
    pop r30

    ;; assings r27 and r26 to their original values, since the Strlen call alters them
    mov r27, r31
    mov r26, r30

    ;; computes half of the string length (r21)
    mov r23, r24            ; copies the string length

    ;; checks if the string is empty
    ;; empty strings are NOT palindromes
    cpi r23, 0
    breq 5f

    ldi r28, 0              ; sets the iteration variable (callee-saved)
    lsr r24                 ; half of the length of the string parameter (shifts right by 1)
    mov r21, r24            ; copies half of the length (upper limit of the for loop)

    ;; obtains a pointer to the last char (r16)      
    add r26, r15
    adc r27, r25
    sbiw r26, 1             ; pointer to the end of the string
    ld r16, X               ; pointer copied to new register (X must be loaded, not r26)

    ;; determines whether the string is a palindrome
3:
    cp r28, r21             ; checks whether the middle char has been reached
    brge 6f                 ; if yes, branch

    ;; if no, continue checking if the string parameter is a palindrome
    ld r17, Z+              ; char at front
    cp r17, r16             ; determines whether the chars are equal
    brne 5f                 ; if no, branch
    ld r16, -X              ; char at back (moves the pointer to the end left by 1)

    inc r28                 ; increments the iteration variable
    jmp 3b                  ; goes to the start of the loop
5:
    ;; callee-saved registers popped
    pop r28
    pop r17
    pop r16
    pop r15

    clr r25
    clr r24
    ldi r24, 0      ; returns 0 if the string is NOT a palindrome
    ret
6:
    ;; callee-saved registers popped
    pop r28
    pop r17
    pop r16
    pop r15
    
    clr r25
    clr r24
    ldi r24, 1      ; returns 1 if the string is a palindrome
    ret

Strlen:
    ;;; uint16_t Strlen(char *arg)
    mov r27, r25    ; loads r25 into r27 (copies argument to X)
    mov r26, r24    ; loads r24 into r26 (copies argument to X)
    clr r25         ; initializes return value to zero
    clr r24
2:  
    ld r23, X+      ; increments register by 1
    cpi r23, 0      ; 0 equivalent to NULL in C, cpi for register and immediate value
    breq 1f         ; if loaded value was zero, branch 1f (label 1, forward)
    adiw r24, 1     ; increments return value (MUST USE ADIW AS OPPOSED TO INC)
    jmp 2b          ; jump 2b (label 2, backward)
1:
    ret
;;; Recursive implementation of factorial

.global factorial
factorial:
       ;; recursive computation of factorial
       tst r24             ; base case check (if value == 0)
       breq 1f
       push r24
       dec r24
       clr r25
       call factorial      ; recursive call
       pop r23             ; (original value of r24)
       mul r24, r23        ; factorial(n - 1) * n
       movw r24, r0        ; copies r1:r0 to r25:r24 
                           ; movw is a register pair copy
       clr r1              ; making sure is 0
       jmp 2f
1: 
       clr r25             ; base case (value of 1)
       ldi r24, 1

2:         
       ret


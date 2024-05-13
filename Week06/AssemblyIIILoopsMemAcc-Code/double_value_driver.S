;;; Example - calls double_value and prints result

        .data                   
value:                          ; A label is an address; value is
	.byte 15                ; the address of 15 in memory

        .text                 
.global main                  
main:                          
        call init_serial_stdio 

        lds r18, value          ; Loading value to double
        clr r25                 ; Setting argument for double_value function
        mov r24, r18            ; We must use r25 and r24
        
        call double_value       ; Calling the function.  Function will leave
                                ; Result in r25:r24.  This is what pint needs
        call pint               ; Printing the value
        call prt_newline        

        cli                     ; Stopping program
        sleep                          

        ret                    



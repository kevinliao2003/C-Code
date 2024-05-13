;;; double_value function implementation.  Receives a uint8_t
;;; and returns the value doubled

;;; double_value
	.global double_value    

double_value: 
              add r24, r24
              clr r25         
              ret            

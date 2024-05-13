
;;; double_value
	.global double_value    

double_value: 
              add r24, r24     ; the value of an int is doubled
              clr r25          ; No necessary, but just for completeness
              ret              ; Always add ret first so you don't forget
                               


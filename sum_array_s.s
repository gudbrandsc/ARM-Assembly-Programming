	.global sum_array_s
	.func sum_array_s

sum_array_s:
	MOV R2, #0 // int: i
	MOV R3, #0 // int: Sum

LOOP:	
	CMP R2,R1 //If i<= array.length
	BGE DONE // Branch
	LSL R4, R2, #2 //R4 = i * 4
	LDR R5, [R0,R4] //R5 = array[i]
	ADD R3,R3,R5 // sum = sum+array[i]
	ADD R2,R2,#1 // i = i+1
	B LOOP //Repeat loop
DONE:	
	MOV R0,R3
	bx lr

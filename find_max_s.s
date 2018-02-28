	.global find_max_s
	.func find_max_s
	
find_max_s:
	MOV R2, #0 // int i
	MOV R3, #0 //int res

LOOP:
	CMP R2,R1 //if i<= array.length
	BGE DONE // Exit
	LSL R4, R2, #2 //R4 = i + 1
	LDR R5, [R0,R4] // R5 = array[i]
	ADD R2, R2, #1 // i= i + 1
	CMP R5,R3 // if(array[i] >= res)
	BGE SET_LARGEST // if(array[i) >= res -> if true
	B LOOP //Repeat loop
	
DONE:
	MOV R0,R3
	bx lr
SET_LARGEST:
	MOV R3,R5
	B LOOP

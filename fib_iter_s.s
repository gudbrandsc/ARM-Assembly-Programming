	.global fib_iter_s
	.func fib_iter_s
fib_iter_s:
	MOV R1, #0 // int f1
	MOV R2, #1 // int f2
	MOV R3, #1 // int i
	MOV R4, #0 // int res
	CMP R0, #1 // if(n>1)
	BLS RETURN_ONE //if not
LOOP:
	CMP R3,R0 //if i == n
	BGE DONE // if true end
	ADD R4, R2, R1  // sum = f1 + f2
	ADD R3, R3, #1 // i=i+1
	MOV R1, R2 // f1 = f2
	MOV R2, R4
	B LOOP
DONE:
	MOV R0,R4
	bx lr
	
RETURN_ONE:
	MOV R0,#1
	bx lr

	.global fib_rec_s
	.func fib_rec_s

fib_rec_s:
	SUB sp, sp, #16
	STR lr, [sp]

	CMP R0, #0 // if n == 0
	MOVEQ R0, #0 // return 0
	BEQ END // end fuction 
	CMP R0, #1 // if n == 1 
	MOVEQ r0, #1 // return 1
	BEQ END // end fuction 
	BNE REC // else call recursive
	B END
REC:	
	STR R0, [sp, #4] //Store R0 in sp
	SUB R0, R0, #1 // n-1
	BL fib_rec_s //Call fib_rec_s(n-1)
	STR R0, [sp,#8]
	LDR R0, [sp,#4]
	SUB R0, R0, #2 //n-2
	BL fib_rec_s // call fib_rec_s(n-2)
	LDR R1, [sp,#8]
	ADD R0,R1,R0 // add fib(n-1)+fib(n-2)
END:
	LDR lr, [sp] 
	ADD sp, sp, #16
	bx lr	//return R0

	.global sum_array_s
	.func sum_array_s

sum_array_s:
	push {r4, r5}
	mov r2, #0 // int: i
	mov r3, #0 // int: Sum
loop:	
	cmp r2, r1 //If i<= array.length
	bge done // Branch
	lsl r4, r2, #2 //R4 = i * 4
	ldr r5, [r0, r4] //R5 = array[i]
	add r3, r3, r5 // sum = sum+array[i]
	add r2, r2, #1 // i = i+1
	b loop //Repeat loop
done:
	mov r0, r3 //Move sum to return register
	pop {r4, r5}
	bx lr  //return 

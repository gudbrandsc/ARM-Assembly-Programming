	.global find_str_s
	.func find_str_s

find_str_s:
	push {r4, r5, r6, r7, r8}
	mov r2, #0 // int i
	ldrb r3, [r1, #0] // r3 == sub[0]
	b loop // start iteration

loop:	
	ldrb r4, [r0, r2] //r4 = string[i]
	cmp r4, #0 // string[i] == \0
	moveq r0, #-1 //Not found
	beq end // end
	cmp r4, r3 // compare string[i]==sub[0]
	moveq r5, r2 // int j = i
	add r2, r2, #1 //i++	
	beq look_for_match //if string[i] == sub[0]
	bne loop // loop back
	
look_for_match:
	mov r6, #0 // int k = 0
	mov r7, r5 // start index of return = i
	b loop_sub
	
loop_sub:
	ldrb r8, [r1, r6] // r8 = sub[k]
	cmp r8, #0 // if k == \n
	bne while_not_end
	moveq r0, r7 // set return value
	beq end // return index
	
while_not_end:	
	ldrb r4, [r0, r5] // r4 = string[i]
	cmp r4, r8 // string[j] == sub[k]
	bne loop // if string[j] != sub[k]
	add r5, r5, #1 // j++
	add r6, r6, #1 // k++
	beq loop_sub // loop_sub array
	
end:
	pop {r4, r5, r6, r7, r8}
	bx lr
	
	

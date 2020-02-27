	area ls,code,readonly
n rn 2
entry 
	adr r0,values
	adr r1,key
	mov n,#10
	ldr r4,[r1]
test	ldr r3,[r0],#4
		sub n,n,#1
		cmp r4,r3
		beq result
		cmp n,#0
		bne test
go b go
result mov r10,#1
values dcd 1,2,3,4,5,6,7,8,9,10
key dcd 7
	end

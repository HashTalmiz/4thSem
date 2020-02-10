	area sum,code,readonly
entry
		mov r0,#0
		mov r1,#1
		mov r2,#5;count
loop  BL SQU
		add r0,r0,r3
		add r1,r1,#1
		sub r2,r2,#1
		cmp r2,#0
		BNE loop
stop  b stop
SQU mul r3,r1,r1
		mov r15,r14
		end

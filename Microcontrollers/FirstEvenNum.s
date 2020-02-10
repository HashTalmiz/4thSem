	area even,code,readonly
;entry
		mov r0,#0
		mov r1,#2 ;sum
		mov r2,#0
loop	add r0,r0,r1
		add r1,r1,#2
		add r2,r2,#1
		cmp r2,#5
		bne loop
stop	b stop

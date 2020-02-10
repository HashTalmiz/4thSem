	area factorial,code,readonly
entry
		mov r0,#1;factorial
		mov r1,#5;n
loop	MUL r0,r1,r0
		sub r1,r1,#1
		cmp r1,#0
		bne loop
stop	b stop
		

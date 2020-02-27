			area fibo,code,readonly
entry
			mov r0,#10;counter
			mov r1,#0;n-2
			mov r2,#1;n-1
			ldr r3,=FIBO
			str r1,[r3],#4
			str r2,[r3],#4
			sub r0,r0,#2
loop		add r1,r1,r2
			str r1,[r3],#4
			eor r1,r1,r2
			eor r2,r1,r2
			eor r1,r1,r2
			subs r0,r0,#1
			bne loop
stop	b stop
			area spc,data
FIBO space 10
			end
				;compiled with 0 errors

	area div,code,readonly
entry
		mov r0,#3
		mov r1,#25
		mov r2,#0
again subs r1,r1,r0
		addpl r2,r2,#1
		bpl again
		addmi r1,r1,r0
stop b stop
	end
  
  ;0 errors

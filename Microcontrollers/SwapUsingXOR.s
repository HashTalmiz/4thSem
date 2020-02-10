	area swap,code,readonly
entry
		ldr r0,=0x12345678
		ldr r1,=0xFFFFFFFF
		EOR R0,R0,R1
		EOR R1,R0,R1
		EOR R0,R0,R1
STOP B STOP
END

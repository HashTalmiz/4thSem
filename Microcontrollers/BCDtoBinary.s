				area bcd_hex,code,readonly
					ENTRY
RADIX					RN		0
LNM					RN		1
UNM					RN 		2
LNIBBLE					RN		3
UNIBBLE					RN		4
RES					RN		5
BYTE					RN		6
NOBYTES					RN		7

					mov RES,#0
					mov RADIX,#16
					mov NOBYTES,#4
					ldr	r8,=NUMBER
					ADD R8,R8,NOBYTES
LOOP			SUB R8,R8,#1
					LDRB R9,[R8]
					LDR LNM,=0x0F
					LDR UNM,=0XF0
					AND	LNIBBLE,R9,LNM
					AND UNIBBLE,R9,UNM
					LSR	UNIBBLE,#4
					MLA RES,RADIX,RES,UNIBBLE
					MLA RES,RADIX,RES,LNIBBLE
					SUBS NOBYTES,NOBYTES,#1
					BNE LOOP
					LDR R8,=0x40000000
					STR R9,[R8]
STOP	B	STOP
NUMBER DCD 00000125
					END
					
					;Compiled with 0 errors

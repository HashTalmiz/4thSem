	area bcd_hex,code,readonly
radix		RN 0
lnm			RN 1
unm			RN 2
lnibble 		RN 3
unibble 		RN 4
res 			RN 5
byte 			RN 6
nobytes	RN 7
ENTRY
	mov res,#0
	mov nobytes,#4
	ldr R8,=NUMBER
	add r8,r8,nobytes
	sub r8,r8,#1
loop 	ldrb r9,[r8],#-1
		mov lnm,#0x0F
		mov unm,#0xF0
		and lnibble,r9,lnm
		and unibble,r9,unm
		lsr unibble,unibble,#4
		mla res,radix,res,unibble
		mla res,radix,res,lnibble
		subs nobytes,nobytes,#1
		bne loop
stop	b stop

NUMBER dcd 00000112
	end
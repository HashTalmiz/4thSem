	area npr,code,readonly
n		rn 0
r		rn 1
res	rn 2
diff	rn	3
entry
	mov res,#1
	mov n,#5
	mov r,#2
	sub diff,n,r
loop	mul res,n,res
		sub n,n,#1
		cmp n,diff
		bne loop
stop	b stop
	end
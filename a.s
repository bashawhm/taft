	.globl _main
	.p2align 4
str.write.inum:
	.asciz "%ld"
str.writeln.inum:
	.asciz "%ld\n"
str.write.rnum:
	.asciz "%f"
str.writeln.rnum:
	.asciz "%f\n"
boo:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	call boo
	movq INVALID OFFSET
	addq INVALID OFFSET

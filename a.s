	.globl _main
str.write.inum:
	.asciz "%d"
str.writeln.inum:
	.asciz "%d\n"
str.write.rnum:
	.asciz "%f"
str.writeln.rnum:
	.asciz "%f\n"
_main:
	pushq %rbp
	movq %rsp, %rbp
	subq $24, %rsp
	popq %rbp
	ret

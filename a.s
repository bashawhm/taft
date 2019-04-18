	.globl _main
str.write.inum:
	.asciz "%d"
str.writeln.inum:
	.asciz "%d\n"
str.write.rnum:
	.asciz "%f"
str.writeln.rnum:
	.asciz "%f\n"
main1:
	pushq %rbp
	movq %rsp, %rbp
	subq $24, %rsp
	movq $13, %rax
	movq $14, %rbx
	imulq $4, %rbx
	addq %rbx, %rax
	movq %rax, %rsi
	leaq str.writeln.inum(%rip), %rdi
	call _printf
	leave
	retq
_main:
	call main1
	popq %rbp
	retq

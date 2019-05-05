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
bar:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq $5, %rbx
	movq %rbx, %rax
	addq $8, %rsp
	pop %rbp
	retq
foo:
	pushq %rbp
	movq %rsp, %rbp
	subq $24, %rsp
	call bar
	movq %rax, %rcx
	movq %rbx, -8(%rbp)
	movq $12, %rbx
	movq -8(%rbp), %rcx
	imulq $2, %rcx
	addq %rcx, %rbx
	movq %rbx, %rax
	addq $24, %rsp
	pop %rbp
	retq
main1:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq $5, %rcx
	call foo
	movq %rax, %rcx
	movq %rbx, -8(%rbp)
	movq -8(%rbp), %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	addq $8, %rsp
	pop %rbp
	retq
_main:
	call main1
	retq

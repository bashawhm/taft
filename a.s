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
main1:
	pushq %rbp
	movq %rsp, %rbp
	subq $56, %rsp
	movq $0, %rbx
	movq %rbx, -48(%rbp)
LB0:
	movq $5, %rbx
	movq -48(%rbp), %rcx
	cmpq %rbx, %rcx
	jge LB1
	movq -48(%rbp), %rbx
	movq -48(%rbp), %rcx
	addq $1, %rcx
	imulq $-1, %rcx
	movq %rbx, (%rbp, %rcx, 8)
	movq -48(%rbp), %rcx
	addq $1, %rcx
	imulq $-1, %rcx
	movq %rbx, (%rbp, %rcx, 8)
	movq %rbx, %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	movq -48(%rbp), %rcx
	addq $1, %rcx
	imulq $-1, %rcx
	movq %rbx, (%rbp, %rcx, 8)
	movq -48(%rbp), %rbx
	addq $1, %rbx
	movq %rbx, -48(%rbp)
	jmp LB0
LB1:
	addq $56, %rsp
	pop %rbp
	retq
_main:
	call main1
	retq

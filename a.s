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
	subq $40, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	movq $1, %rbx
	movq %rbx, -16(%rbp)
	leaq str.write.inum(%rip), %rdi
	leaq -24(%rbp), %rsi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _scanf
	popq %rcx
	popq %rax
	movq $0, %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	movq $1, %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	movq $2, %rbx
	movq %rbx, -32(%rbp)
LB0:
	movq -24(%rbp), %rbx
	movq -32(%rbp), %rcx
	cmpq %rbx, %rcx
	jge LB1
	movq -8(%rbp), %rbx
	addq -16(%rbp), %rbx
	movq %rbx, -40(%rbp)
	movq -16(%rbp), %rbx
	movq %rbx, -8(%rbp)
	movq -40(%rbp), %rbx
	movq %rbx, -16(%rbp)
	movq -40(%rbp), %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	movq -32(%rbp), %rbx
	addq $1, %rbx
	movq %rbx, -32(%rbp)
	jmp LB0
LB1:
	addq $40, %rsp
	pop %rbp
	retq
_main:
	call main1
	retq

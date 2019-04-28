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
	subq $8, %rsp
	leaq str.write.inum(%rip), %rdi
	leaq -8(%rbp), %rsi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _scanf
	popq %rcx
	popq %rax
LB0:
	movq $0, %rbx
	movq -8(%rbp), %rcx
	cmpq %rbx, %rcx
	jle LB1
	movq -8(%rbp), %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	movq -8(%rbp), %rbx
	subq $1, %rbx
	movq %rbx, -8(%rbp)
	jmp LB0
LB1:
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

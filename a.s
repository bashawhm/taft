	.globl _main
str.write.inum:
	.asciz "%d"
str.writeln.inum:
	.asciz "%d\n"
str.write.rnum:
	.asciz "%f"
str.writeln.rnum:
	.asciz "%f\n"
foo:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movl $43, %esi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	movq $5, %rbx
	movq %rbx, %rax
	addq $8, %rsp
	pop %rbp
	retq
main1:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq -8(%rbp), %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	leaq str.write.inum(%rip), %rdi
	leaq -8(%rbp), %rsi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _scanf
	popq %rcx
	popq %rax
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

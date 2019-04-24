	.globl _main
str.write.inum:
	.asciz "%d"
str.writeln.inum:
	.asciz "%d\n"
str.write.rnum:
	.asciz "%f"
str.writeln.rnum:
	.asciz "%f\n"
MyProcedure:
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
	addq $8, %rsp
	pop %rbp
	retq
main1:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq $13, %rax
	movq $14, %rbx
	imulq $4, %rbx
	addq %rbx, %rax
	movq %rax, %rsi
	leaq str.writeln.inum(%rip), %rdi
	pushq %rax
	pushq %rcx
	movb $0, %al
	call _printf
	popq %rcx
	popq %rax
	call MyProcedure
	movl $4, %esi
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

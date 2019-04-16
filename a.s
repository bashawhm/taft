	.globl _main
str.write.inum:
	.asciz "%d"
str.writeln.inum:
	.asciz "%d\n"
str.write.rnum:
	.asciz "%f"
str.writeln.rnum:
	.asciz "%f\n"
bar:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	leave
	retq
baz:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	call bar
	leave
	retq
bar2:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	leave
	retq
foo:
	pushq %rbp
	movq %rsp, %rbp
	subq $24, %rsp
	call bar
	leave
	retq
boo:
	pushq %rbp
	movq %rsp, %rbp
	subq $40, %rsp
	leaq str.writeln.inum(%rip), %rdi
	call _printf
	leaq str.writeln.inum(%rip), %rdi
	call _printf
	leave
	retq
main1:
	pushq %rbp
	movq %rsp, %rbp
	subq $96, %rsp
	call boo
	call foo
	leave
	retq
_main:
	call main1
	popq %rbp
	retq

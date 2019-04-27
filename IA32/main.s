	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movq	$0, -16(%rbp)
	leaq	L_.str(%rip), %rdi
	leaq	-16(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	cmpq	$5, -16(%rbp)
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	jge	LBB0_2
## %bb.1:
	movq	$-10, -16(%rbp)
LBB0_2:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%ld"


.subsections_via_symbols

	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	movl	$5, %ecx
	movl	%ecx, %edx
	movl	$0, -4(%rbp)
	movq	$5, -16(%rbp)
	movq	-16(%rbp), %rsi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movq	%rsi, %rax
	movq	%rdx, -32(%rbp)         ## 8-byte Spill
	cqto
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	idivq	%rsi
	movq	%rax, -16(%rbp)
	movl	-20(%rbp), %eax         ## 4-byte Reload
	popq	%rbp
	retq
                                        ## -- End function

.subsections_via_symbols

	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jne	LBB0_3
## %bb.1:
	cmpl	$1, -8(%rbp)
	jne	LBB0_3
## %bb.2:
	jmp	LBB0_3
LBB0_3:
	xorl	%eax, %eax
	popq	%rbp
	retq
                                        ## -- End function

.subsections_via_symbols

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
	cmpl	$5, -8(%rbp)
	jge	LBB0_2
## %bb.1:
	movl	$6, -8(%rbp)
	jmp	LBB0_3
LBB0_2:
	movl	$7, -8(%rbp)
LBB0_3:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
                                        ## -- End function

.subsections_via_symbols

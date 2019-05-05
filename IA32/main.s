	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -36(%rbp)
	movl	$2, -40(%rbp)
	movl	$1, -44(%rbp)
	movl	-40(%rbp), %ecx
	addl	-44(%rbp), %ecx
	movslq	%ecx, %rax
	movl	-32(%rbp,%rax,4), %ecx
	movl	%ecx, -48(%rbp)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rax
	jne	LBB0_2
## %bb.1:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_2:
	callq	___stack_chk_fail
	ud2
                                        ## -- End function

.subsections_via_symbols

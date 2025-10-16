	.file	"sort.c"
	.text
	.globl	a
	.bss
	.align 32
	.type	a, @object
	.size	a, 400
a:
	.zero	400
	.text
	.globl	sort
	.type	sort, @function
sort:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rax
	addq	$4, %rax
	cmpq	-64(%rbp), %rax
	jnb	.L15
	movq	-64(%rbp), %rax
	subq	-56(%rbp), %rax
	sarq	$2, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	sort
	movq	-64(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	sort
	leaq	a(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L4
.L8:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L5
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -24(%rbp)
	jmp	.L6
.L5:
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -16(%rbp)
.L6:
	addq	$4, -32(%rbp)
.L4:
	movq	-24(%rbp), %rax
	cmpq	-8(%rbp), %rax
	jnb	.L9
	movq	-16(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jb	.L8
	jmp	.L9
.L10:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -32(%rbp)
	addq	$4, -24(%rbp)
.L9:
	movq	-24(%rbp), %rax
	cmpq	-8(%rbp), %rax
	jb	.L10
	jmp	.L11
.L12:
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -32(%rbp)
	addq	$4, -16(%rbp)
.L11:
	movq	-16(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jb	.L12
	leaq	a(%rip), %rax
	movq	%rax, -32(%rbp)
	jmp	.L13
.L14:
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-56(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -56(%rbp)
	addq	$4, -32(%rbp)
.L13:
	movq	-56(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jb	.L14
	jmp	.L1
.L15:
	nop
.L1:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sort, .-sort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

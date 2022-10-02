	.file	"hisimd.c"
	.text
	.p2align 4,,15
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	xorl	%eax, %eax
	.p2align 4,,7
	.p2align 3
.L2:
	movl	b(,%eax,4), %edx
	addl	c(,%eax,4), %edx
	movl	%edx, a(,%eax,4)
	addl	$1, %eax
	cmpl	$256, %eax
	jne	.L2
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	xorl	%eax, %eax
	.p2align 4,,7
	.p2align 3
.L6:
	movl	b(,%eax,4), %edx
	addl	c(,%eax,4), %edx
	movl	%edx, a(,%eax,4)
	addl	$1, %eax
	cmpl	$256, %eax
	jne	.L6
	xorw	%ax, %ax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.comm	c,1024,32
	.comm	b,1024,32
	.comm	a,1024,32
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

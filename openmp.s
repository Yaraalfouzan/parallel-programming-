	.file	"openmp.c"
	.text
	.globl	_generate_vector
	.def	_generate_vector;	.scl	2;	.type	32;	.endef
_generate_vector:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$0, -12(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ebx
	call	_rand
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$100, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fstpl	(%ebx)
	addl	$1, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L3
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Usage: %s <vector_size>\12\0"
LC3:
	.ascii "Euclidean Distance: %f\12\0"
LC4:
	.ascii "Time taken: %f seconds\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$80, %esp
	call	___main
	cmpl	$2, 8(%ebp)
	je	L5
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$1, %eax
	jmp	L6
L5:
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, 76(%esp)
	movl	76(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, 72(%esp)
	movl	76(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, 68(%esp)
	movl	76(%esp), %eax
	movl	%eax, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_generate_vector
	movl	76(%esp), %eax
	movl	%eax, 4(%esp)
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_generate_vector
	fldz
	fstpl	56(%esp)
	call	_omp_get_wtime
	fstpl	48(%esp)
	fldl	56(%esp)
	fstpl	16(%esp)
	movl	68(%esp), %eax
	movl	%eax, 32(%esp)
	movl	72(%esp), %eax
	movl	%eax, 28(%esp)
	movl	76(%esp), %eax
	movl	%eax, 24(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	leal	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$_main._omp_fn.0, (%esp)
	call	_GOMP_parallel
	fldl	16(%esp)
	fstpl	56(%esp)
	fldl	56(%esp)
	fstpl	(%esp)
	call	_sqrt
	fstpl	56(%esp)
	call	_omp_get_wtime
	fstpl	40(%esp)
	fldl	56(%esp)
	fstpl	4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	fldl	40(%esp)
	fsubl	48(%esp)
	fstpl	4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, %eax
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.def	_main._omp_fn.0;	.scl	3;	.type	32;	.endef
_main._omp_fn.0:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	fldz
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -40(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -44(%ebp)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %ebx
	call	_omp_get_num_threads
	movl	%eax, %esi
	call	_omp_get_thread_num
	movl	%eax, %edi
	movl	%ebx, %eax
	cltd
	idivl	%esi
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%esi
	movl	%edx, %eax
	cmpl	%eax, %edi
	jl	L8
L12:
	imull	%ecx, %edi
	movl	%edi, %edx
	addl	%edx, %eax
	leal	(%eax,%ecx), %edx
	cmpl	%edx, %eax
	jge	L9
	movl	%eax, -36(%ebp)
L10:
	movl	-36(%ebp), %eax
	leal	0(,%eax,8), %ecx
	movl	-44(%ebp), %eax
	addl	%ecx, %eax
	fldl	(%eax)
	movl	-36(%ebp), %eax
	leal	0(,%eax,8), %ecx
	movl	-40(%ebp), %eax
	addl	%ecx, %eax
	fldl	(%eax)
	fsubrp	%st, %st(1)
	fstpl	-56(%ebp)
	fldl	-56(%ebp)
	fmull	-56(%ebp)
	fldl	-32(%ebp)
	faddp	%st, %st(1)
	fstpl	-32(%ebp)
	addl	$1, -36(%ebp)
	cmpl	%edx, -36(%ebp)
	jl	L10
L9:
	movl	8(%ebp), %eax
	movl	%eax, %esi
	fildq	(%esi)
	fistpq	-72(%ebp)
L11:
	fldl	-72(%ebp)
	faddl	-32(%ebp)
	fstpl	-88(%ebp)
	movl	-88(%ebp), %eax
	movl	-84(%ebp), %edx
	movl	%eax, %ecx
	movl	%edx, %ebx
	movl	-72(%ebp), %eax
	movl	-68(%ebp), %edx
	movl	%ecx, -88(%ebp)
	movl	%ebx, -84(%ebp)
	movl	%ecx, %ebx
	movl	-84(%ebp), %ecx
	lock cmpxchg8b	(%esi)
	movl	-72(%ebp), %ecx
	movl	-68(%ebp), %ebx
	movl	%eax, -72(%ebp)
	movl	%edx, -68(%ebp)
	movl	%eax, %edi
	xorl	%ecx, %edi
	movl	%edi, -80(%ebp)
	movl	%edx, %eax
	xorl	%ebx, %eax
	movl	%eax, -76(%ebp)
	movl	-80(%ebp), %edx
	movl	-76(%ebp), %ecx
	movl	%ecx, %eax
	orl	%edx, %eax
	testl	%eax, %eax
	jne	L11
	jmp	L13
L8:
	movl	$0, %eax
	addl	$1, %ecx
	jmp	L12
L13:
	addl	$76, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_atoi;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_omp_get_wtime;	.scl	2;	.type	32;	.endef
	.def	_GOMP_parallel;	.scl	2;	.type	32;	.endef
	.def	_sqrt;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_omp_get_num_threads;	.scl	2;	.type	32;	.endef
	.def	_omp_get_thread_num;	.scl	2;	.type	32;	.endef

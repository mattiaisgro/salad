	.file	"main.cpp"
	.section	.text.unlikely,"x"
LCOLDB0:
	.text
LHOTB0:
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1371:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE1371:
	.section	.text.unlikely,"x"
LCOLDE0:
	.text
LHOTE0:
	.section	.text.unlikely,"x"
LCOLDB1:
	.text
LHOTB1:
	.p2align 4,,15
	.def	__ZN8asmsalad9__pow_negIiEEKT_S1_S1_.part.1;	.scl	3;	.type	32;	.endef
__ZN8asmsalad9__pow_negIiEEKT_S1_S1_.part.1:
LFB1374:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$1, %ecx
	movl	%eax, %ebx
	subl	$8, %esp
	.cfi_def_cfa_offset 16
	cmpl	$-1, %edx
	jne	L13
	movl	%ebx, %eax
	addl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	cltd
	idivl	%ecx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L13:
	.cfi_restore_state
	cmpl	$-2, %edx
	jne	L14
L4:
	movl	%ebx, %eax
	addl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	cltd
	idivl	%ecx
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L14:
	.cfi_restore_state
	addl	$3, %edx
	je	L5
	call	__ZN8asmsalad9__pow_negIiEEKT_S1_S1_.part.1
	movl	%eax, %ecx
L5:
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	movl	%eax, %ecx
	jmp	L4
	.cfi_endproc
LFE1374:
	.section	.text.unlikely,"x"
LCOLDE1:
	.text
LHOTE1:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.unlikely,"x"
LCOLDB2:
	.section	.text.startup,"x"
LHOTB2:
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1271:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	call	___main
	movl	$__ZSt4cout, %ecx
	movl	$1, (%esp)
	call	__ZNSolsEi
	subl	$4, %esp
	movl	%eax, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1271:
	.section	.text.unlikely,"x"
LCOLDE2:
	.section	.text.startup,"x"
LHOTE2:
	.section	.text.unlikely,"x"
LCOLDB3:
	.section	.text.startup,"x"
LHOTB3:
	.p2align 4,,15
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1372:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1372:
	.section	.text.unlikely,"x"
LCOLDE3:
	.section	.text.startup,"x"
LHOTE3:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 4.9.3"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef

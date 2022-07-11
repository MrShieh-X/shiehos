	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"test.c"
	.def	main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	subq	$56, %rsp
	.seh_stackalloc 56
	.seh_endprologue
	movl	$0, 52(%rsp)
	movl	$11111, %ecx                    # imm = 0x2B67
	movl	$22222, %edx                    # imm = 0x56CE
	movl	$33333, %r8d                    # imm = 0x8235
	movl	$44444, %r9d                    # imm = 0xAD9C
	movl	$55555, 32(%rsp)                # imm = 0xD903
	movl	$66666, 40(%rsp)                # imm = 0x1046A
	callq	say_hi
	xorl	%eax, %eax
	addq	$56, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.addrsig
	.addrsig_sym say_hi

SECTION .TEXT
	GLOBAL hlt
	GLOBAL cli
	GLOBAL sti
	GLOBAL nop

; 1st：rdi
; 2nd：rsi
; 3rd：rdx
; 4th：rcx
; 5th：r8
; 6th：r9
; 7th：[esp+8]
; 8th：[esp+16]
; 9th：[esp+24]
; 10th：[esp+32]
; 11th：[esp+40]
hlt:
    mov rax,50000
    hlt
    ret

cli:
    cli
    ret

sti:
    sti
    ret

nop:
    nop
    ret
SECTION .TEXT
	GLOBAL say_hi

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
say_hi:
    mov rax,[esp+56]
    ret
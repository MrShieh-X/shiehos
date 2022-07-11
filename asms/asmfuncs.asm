SECTION .TEXT
	GLOBAL say_hi

say_hi:
    cmp byte[rsp+2282],2222
    je a
       ret

a:
        mov rax,2280
        ret

finish:
ret

;say_hi:
;    mov rax,[rsp+41]
;    ret
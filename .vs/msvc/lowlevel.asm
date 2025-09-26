; lowlevel.asm
.CODE

PUBLIC inw
PUBLIC outw

inw PROC port:WORD
    mov dx, port
    in ax, dx
    movzx rax, ax
    ret
inw ENDP

outw PROC port:WORD, value:WORD
    mov dx, port
    mov ax, value
    out dx, ax
    movzx rax, dx
    ret
outw ENDP

END
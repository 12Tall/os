; 立即数若以字母开头则前面必须补零，否则会被认为是标号
org 07c00h         ; origin from 0x7c00h

; set ds=es=cs
mov ax, cs
mov ds, ax
mov es, ax

call DispStr        ; call function to show str

jmp $               ; loop

DispStr:
    mov ax, BootMessage
    mov bp, ax      ; es:bp <= address of string
    mov cx, 16      ; string length
    mov ax, 01301h  ; AH <= 13h, AL <= 01H
    mov bx, 000ch   ; display style
    mov dl, 0
    int 10h          ; #10h intterupt of bios
    ret

BootMessage:
    db "Hello, OS world!"

times 510-($-$$) db 0
; $ address of current line
; $$ address of current segment begin

dw 0xaa55           ; end



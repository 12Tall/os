%include "FAT12.inc"
org 07c00h

FAT12Header LABEL_START, "12tall  ", "VolLabel_11"

LABEL_START:
    mov	ax, cs
	mov	ds, ax
	mov	es, ax
	Call	DispStr			; 调用显示字符串例程
	jmp	$			; 无限循环
DispStr:
	mov	ax, BootMessage
	mov	bp, ax			; ES:BP = 串地址
	mov	cx, 16			; CX = 串长度
	mov	ax, 01301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)
	mov	dl, 0
	int	10h			; int 10h
	ret
	
BootMessage:		db	"Hello, OS world!",0
times 	510-($-$$)	db	0	; 填充剩下的空间，使生成的二进制代码恰好为512字节
dw 	0xaa55				; 结束标志
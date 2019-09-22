; Gate
; Usage: Gate Descriptor_Adress , Section_Adress
;   Descriptor:   dw
;   Section:     dd
%macro Init_Descriptor 2
	xor eax, eax	; reset eax
	mov ax, cs		; 
	shl eax, 4		; eax = cs << 4
	add eax, %2	    ; addr of section
	mov word [%1 + 2], ax
	shr eax, 16
	mov byte [%1 + 4], al
	mov byte [%1 + 7], ah
%endmacro  
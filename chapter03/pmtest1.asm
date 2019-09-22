%include "pm.inc"	; constant, macro
%include "func.inc"

org 07c00h
jmp LABEL_BIGIN		; 4 bytes

section .gdt		; GDT section, allocate memory space only
; ======================================================================
; ----------------------------------------------------------------------
; label:						base;	limit;			attr;(8 bytes)
LABEL_GDT:			Descriptor 	0, 		0, 				0
LABEL_DESC_CODE32:	Descriptor	0,		SegCode32Len-1,	DA_C + DA_32	; uncoordinate code section
LABEL_DESC_VIDEO:	Descriptor	0B8000h,0ffffh,			DA_DRW			; video cache section
; -----------------------------------------------------------------------

GdtLen 	equ 	$ - LABEL_GDT	; length of gdt; limit = length-1
GdtPtr	dw 	GdtLen - 1			; !content of gdt register!
		dd 	0					; base of gdt

; Selector: !just constant, not in memory
; -----------------------------------------------------------------------
Selector_Code32 equ LABEL_DESC_CODE32 - LABEL_GDT
Selector_Video 	equ LABEL_DESC_VIDEO - LABEL_GDT
; -----------------------------------------------------------------------
; =======================================================================

section .s16
[BITS 16]
; =======================================================================
LABEL_BIGIN:
	mov	ax, cs
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov sp, 0100h	; aligin to section base

	; init cede32 descriptor
	Init_Descriptor LABEL_DESC_CODE32, LABEL_SEG_CODE32
	; /\
	; ||
	; --------------------------------------------------
	; xor eax, eax	; reset eax
	; mov ax, cs		; 
	; shl eax, 4		; eax = cs << 4
	; add eax, LABEL_SEG_CODE32	; addr of code32 section
	; mov word [LABEL_DESC_CODE32 + 2], ax
	; shr eax, 16
	; mov byte [LABEL_DESC_CODE32 + 4], al
	; mov byte [LABEL_DESC_CODE32 + 7], ah
	; --------------------------------------------------

	; prepare for loading GDTR(gdt register)
	xor eax, eax
	mov ax, ds
	shl eax, 4		; eax = ds << 4
	add eax, LABEL_GDT
	mov dword [GdtPtr + 2], eax	; [GdtPtr+2] = base of gdt

	; load gdt register
	lgdt [GdtPtr]
	cli 

	; open A20
	in al, 92h
	or al, 00000010b
	out 92h, al

	; exchange protect modal
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	; long jmp
	jmp dword Selector_Code32:0

; =======================================================================

section .s32
[BITS 32]
; =======================================================================

LABEL_SEG_CODE32:
	mov ax, Selector_Video	; offset address
	mov gs, ax
	mov edi, (80 * 11 + 79)* 2	; line 11 row 79
	mov ah, 0ch					; font style
	mov al, 'p'
	mov [gs:edi], ax

	jmp $

SegCode32Len equ $ - LABEL_SEG_CODE32	; this line belong to .s32, until
; there is any new section defined before 

; ========================================================================
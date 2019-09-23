%include "pm.inc"

org 07c00h
jmp LABEL_BEGIN

[section .gdt]
; ==========================================================
;
; gdt table
; ----------------------------------------------------------
LABEL_GDT:          Descriptor  0,          0,              0               ; empty
LABEL_DESC_NORMAL:  Descriptor  0,          0ffffh,         DA_DRW          ; Normal section Descriptor
;LABEL_DESC_CODE32:  Descriptor  0,          SegCode32Len -1,DA_C+DA_32      ; uncoordinate code32 section
LABEL_DESC_CODE16:  Descriptor  0,          0ffffh,         DA_C            ; uncoordinate code16 section
;LABEL_DESC_DATA:    Descriptor  0,          DataLen-1,      DA_DRW          ; data
;LABEL_DESC_STACK:   Descriptor  0,          TopOfStack,     DA_DRWA+DA_32   ; stack32 
LABEL_DESC_TEST:    Descriptor  050000h,    0ffffh,         DA_DRW          ; test section over 1M
LABEL_DESC_VIDEO:   Descriptor  0B0000h,    0ffffh,         DA_DRW          ; video cache
; ----------------------------------------------------------
;
; gdt ponitor
; ----------------------------------------------------------
GdtLen  equ $ - LABEL_GDT   ; length of gdt
GdtPtr  dw  GdtLen - 1      ; limit of gdt
        dd  0               ; base of gdt
; ----------------------------------------------------------
;
; gdt selector, just constant
; ----------------------------------------------------------
SelectorNormal  equ     LABEL_DESC_NORMAL - LABEL_GDT
;SelectorCode32  equ     LABEL_DESC_CODE32 - LABEL_GDT
SelectorCode16  equ     LABEL_DESC_CODE16 - LABEL_GDT
;SelectorData    equ     LABEL_DESC_DATA - LABEL_GDT
;SelectorStack   equ     LABEL_DESC_STACK - LABEL_GDT
SelectorTest    equ     LABEL_DESC_TEST - LABEL_GDT
SelectorVideo   equ     LABEL_DESC_VIDEO - LABEL_GDT
; ==========================================================

[section .data1 align=32]
[BITS 32]
; ==========================================================
LABEL_DATA:
SPValueInRealMode   dw  0
PMMessage:          db  "In Protect Mode now. ^-^", 0
OffsetPMMessage     equ PMMessage - $$
StrTest             db  "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0
OffsetStrTest       equ StrTest - $$
DataLen             equ $ - LABEL_DATA
; ==========================================================

[section .gs align=32]
[BITS 32]
; ==========================================================
LABEL_STACK:
    times 320 db 0
TopOfStack equ $ - LABEL_STACK -1



[section .s16]
[BITS 16]
; ===================================================
LABEL_BEGIN:
jmp $

; ===================================================
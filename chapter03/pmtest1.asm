%include "pm.inc"

org 07c00h
jmp LABEL_BEGIN

[section .gdt]
LABEL_GDT: Descriptor 0, 0, 0   ; empty Descriptor
LABEL_DESC_CODE32: Descriptor 0, SegCode32Len - 1, DA_C + DA_32   ; 
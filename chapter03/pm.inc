; protect modal include file

; Descriptor Ⅰ
; ----  ┏━━━┳━━━┓高地址
;       ┃ 7 ┃ B ┃
;       ┣━━━┫ a ┃
;             s
; Byte7 ┆   ┆ e ┆
;
;       ┣━━━┫ 2 ┃
;       ┃ 0 ┃   ┃
; ----  ┣━━━╋━━━┫
;       ┃ 7 ┃ G ┃
;       ┣━━━╋━━━┫
;       ┃ 6 ┃ D ┃
;       ┣━━━╋━━━┫
;       ┃ 5 ┃ 0 ┃
;       ┣━━━╋━━━┫
;       ┃ 4 ┃AVL┃
; Byte6 ┣━━━╋━━━┫
;       ┃ 3 ┃ L ┃
;       ┣━━━┫ i ┃
;       ┃ 2 ┃ m ┃
;       ┣━━━┫ i ┃
;       ┃ 1 ┃ t ┃
;       ┣━━━┫ 2 ┃
;       ┃ 0 ┃   ┃
; ----  ┣━━━╋━━━┫
;       ┃ 7 ┃ P ┃
;       ┣━━━╋━━━┫
;       ┃ 6 ┃   ┃
;       ┣━━━┫DPL┃
;       ┃ 5 ┃   ┃
;       ┣━━━╋━━━┫
;       ┃ 4 ┃ S ┃
; Byte5 ┣━━━╋━━━┫
;       ┃ 3 ┃   ┃
;       ┣━━━┫ T ┃
;       ┃ 2 ┃ Y ┃
;       ┣━━━┫ P ┃
;       ┃ 1 ┃ E ┃
;       ┣━━━┫   ┃
;       ┃ 0 ┃   ┃
; ----  ┣━━━╋━━━┫
;       ┃ 23┃   ┃
;       ┣━━━┫   ┃
;       ┃ 22┃   ┃
;       ┣━━━┫ B ┃
;             a
;  Byte ┆   ┆ s ┆
;  2          e
;  3    ┣━━━┫   ┃
;  4    ┃ 1 ┃ 1 ┃
;       ┣━━━┫   ┃
;       ┃ 0 ┃   ┃
; ----  ┣━━━╋━━━┫
;       ┃ 15┃   ┃
;       ┣━━━┫   ┃
;       ┃ 14┃ L ┃
;       ┣━━━┫ i ┃
;             m
;  Byte ┆   ┆ i ┆
;  0          t
;  1    ┣━━━┫   ┃
;       ┃ 1 ┃ 1 ┃
;       ┣━━━┫   ┃
;       ┃ 0 ┃   ┃
; ----  ┗━━━┻━━━┛低地址


; Descriptor Ⅱ
; 高地址-------------------------------------------------------低地址

; |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0    |
; |7654321076543210765432107654321076543210765432107654321076543210|	<- 共 8 字节
; |--------========--------========--------========--------========|
; ┏━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┓
; ┃31..24 ┃ as following  ┃      Base(23..0)      ┃  Limit(15..0)  ┃
; ┃       ┃               ┃                       ┃                ┃
; ┃ Base2 ┃(3)│(2)│  (1)  ┃ Base1b│    Base1a     ┃     Limit1     ┃
; ┣━━━━━━━╋━━━━━━━┳━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━┫
; ┃   %6  ┃  %5   ┃  %4   ┃  %3   ┃      %2       ┃       %1       ┃
; ┗━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┛
;         │                \_________
;         │                          \__________________
;         │                                             \________________________________________________
;         │                                                                                              \
;         ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
;         ┃  7  ┃  6  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃  7  ┃  6  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
;         ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━┻━━━━━┻━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━┻━━━━━┻━━━━━┻━━━━━┫
;         ┃  G  ┃  D  ┃  0  ┃  AVL┃    Limit 2 (19..16)   ┃  P  ┃    DPL    ┃  S  ┃        TYPE           ┃
;         ┣━━━━━┻━━━━━┻━━━━━┻━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫
;         ┃      (3): Attr 2      ┃     (2): Limit 2      ┃                 (1): Attr1                    ┃
;         ┗━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
;         高地址                                                                                      低地址
;
;

; Descriptor
; Usage: Descriptor Base, Limit, Attr
;   Base: dd
;   Limit: dd(lower 20 bits avaliable)
;   Attr: dw(lower 4 bits of higher byte are always 0)
%macro Descriptor 3
    dw %2 & 0ffffh      ; section limit     ; 2 bytes
    dw %1 & 0ffffh      ; section base      ; 2 bytes
    db (%1 >> 16)& 0ffh ; section base2     ; 1 byte
    dw ((%2 >> 8)& 0ffh)|(%3 & 0f0ffh)  ; section attr1 + limit2 + attr2
                                            ; 2 bytes
    db (%1 >> 24)& 0ffh ; section base3     ; 1 byte
%endmacro               ; 8 bytes

;------------------------------------------------------
;   DA_ : Descriptor Attribute
;   D   : Data Section
;   C   : Code Section
;   S   : System Section
;   R   : Readonly
;   RW  : Read and Write
;   A   : Accessed
;   other....
;------------------------------------------------------

; Descriptor Type
DA_32   equ 4000h   ; 32 bits section

; Descriptor Privilege Level
DA_DPL0 equ 00h     ; DPL=0
DA_DPL1 equ 01h     ; DPL=1
DA_DPL2 equ 02h     ; DPL=2
DA_DPL3 equ 03h     ; DPL=3

; Storage Section(code/data) Descriptor Type
DA_DR   equ 90h     ; data section readonly
DA_DRW  equ 92h     ; data section can be read and write
DA_DRWA equ 93h     ; data section can be w/r which is accessed
DA_C    equ 98h     ;
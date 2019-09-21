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

; 对于属性Attr 的说明：
;
; (1) P:    存在位(Present)
;       P=1 表示描述符对地址的转换是有效的。<在内存中能找到描述符对应的段>
;       P=0 表示描述符对地址的转换是无效的。<使用该描述符访问内存会引发异常>
;
; (2) DPL:  描述符特权级(Descriptor Privilege Level)
;       共两位，4 个特权级。用于特权检查，以确定能否访问该段
; (3) S:    段描述符类型
;       对于存储段(code/data)，S=1
;       对于系统段或者门描述符，S=0
;
; (4) TYPE: 存储段(code/data) 的具体属性
;
;   只有数据段存在上下扩展之分（栈），向上扩展以Base 开始， 向下扩展以Limit 开始
;   data    value       comment             
;           -----------------------------------------------      
;           0           readonly                        R
;           1           readonly,accessed               RA
;           2           read,write                      RW
;           3           read,write,accessed             RWA
;           4           readonly,downward               RD
;           5           readonly,downward,accessed      RDA
;           6           read,write,downward             RWD
;           7           read,write,downward,accessed    RWDA
;
;
;   一致代码段：    操作系统拿出来被共享的代码段,可以被低特权级的用户直接调用访问的代码
;           1) 特权级高的程序不允许访问特权级低的数据:核心态不允许调用用户态的数据
;           2) 特权级低的程序可以访问到特权级高的数据.但是特权级不会改变:用户态还是用户态
;   非一致代码段：  为了避免低特权级的访问而被操作系统保护起来的系统代码
;           1) 只允许同级间访问
;           2) 绝对禁止不同级访问:核心态不用用户态，用户态也不使用核心态
;   code    value       comment             
;           -----------------------------------------------      
;           8           exec                            C
;           9           exec,accessed                   CA
;           A           exec,read                       CR
;           B           exec,read,accessed              CRA
;           C           exec,coordination               CCO
;           D           exec,coordination,accessed      CCOA
;           E           exec,read,coordination          CCOR
;           F           exec,read,coordination,accessed CCORA
;
;
;   系统段
;   system  value       comment             
;           -----------------------------------------------      
;           0           <undefined>
;           1           valiable 286TSS
;           2           LDT
;           3           busy 286TSS
;           4           286 call gate
;           5           task gate
;           6           286 interrupt gate
;           7           286 trap gate
;           8           <undefined>
;           9           valiable 386TSS
;           A           <undefined>
;           B           busy 386TSS
;           C           386 call gate
;           D           <undefined>
;           E           386 interrupt gate
;           F           386 trap gate



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
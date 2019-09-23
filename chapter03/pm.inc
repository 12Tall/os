; protect mode include file

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
;
;
; (5) G: 段界限粒度(Granularity)
;       G=0 表示以字节为单位
;       G=1 表示4KB 为单位
;       粒度只对段界限有效，段基址永远以字节为单位
;
;
; (6) D: 兼容286?
;       1) 可执行段(code?)
;           D=1 默认使用32 位地址及32 位或8 位操作数
;           D=0 默认使用16 位地址及16 位或8 位操作数，与80286 兼容<可以使用地址大小前缀和操作数大小前缀分别改变默认的地址或操作数的大小>
;       2) 向下扩展数据段(stack?),Limit 确定的是下限
;           D=1 上部界限为4GB
;           D=0 上部界限为64KB，与286 兼容
;       3) 由ss 寄存器寻址的段描述符中，D 位决定隐式堆栈访问指令(PUSH/POP)使用何种堆栈指针寄存器
;           D=1 使用32 位ESP
;           D=0 使用16 位SP
;
; (7) AVL: 软件可利用位。386 及其兼容CPU 未对该位做任何规定




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
DA_DPL1 equ 20h     ; DPL=1
DA_DPL2 equ 40h     ; DPL=2
DA_DPL3 equ 60h     ; DPL=3

; Storage Section(code/data) Descriptor Type
DA_DR   equ 90h     ; data section readonly
DA_DRW  equ 92h     ; data section can be read and write
DA_DRWA equ 93h     ; data section can be w/r which is accessed
DA_C    equ 98h     ; code section
DA_CR   equ 9Ah     ; code can be read
DA_CCO  equ 9Ch     ; code coordination
DA_CCOR equ 9Eh     ; code coordination can be read

; System Section(Gate) Descriptor Type
DA_LDT  equ 82h     ; local descriptor table
DA_TaskGate equ 85h ; task gate
DA_386TSS   equ 89h ; 386 task section state
DA_386CGate equ 8Ch ; 386 call gate
DA_386IGate equ 8Eh ; 386 Interruption gate
DA_386TGate equ 8Fh ; 386 trap gate



; Descriptor
; Usage: Descriptor Base, Limit, Attr
;   Base: dd
;   Limit: dd(lower 20 bits avaliable)
;   Attr: dw(lower 4 bits of higher byte are always 0)
%macro Descriptor 3
    dw %2 & 0ffffh      ; section limit     ; 2 bytes
    dw %1 & 0ffffh      ; section base      ; 2 bytes
    db (%1 >> 16)& 0ffh ; section base2     ; 1 byte
    dw ((%2 >> 8)& 0f00h)|(%3 & 0f0ffh)  ; section attr1 + limit2 + attr2
                                            ; 2 bytes
    db (%1 >> 24)& 0ffh ; section base3     ; 1 byte
%endmacro               ; 8 bytes


; Selector
; ┏━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┳━━━━┓
; ┃ 15 ┃ 14 ┃ 13 ┃ 12 ┃ 11 ┃ 10 ┃ 9  ┃ 8  ┃ 7  ┃ 6  ┃ 5  ┃ 4  ┃ 3  ┃ 2  ┃ 1  ┃ 0  ┃
; ┣━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━┻━━━━╋━━━━╋━━━━┻━━━━┫
; ┃                        index of descriptor                     ┃ TI ┃   RPL   ┃
; ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━┻━━━━━━━━━┛
;
; (1) RPL(Requested Privilege Level): 请求特权级，用于特权检查。
;
; (2) TI(Table Indicator): 引用描述符表指示位
;   TI=0 从GDT 读取描述符
;   TI=1 从LDT 读取描述符
;
; Selector Attribute
SA_RPL0 equ 0   ; ┓
SA_RPL1 equ 1   ; ┣ RPL
SA_RPL2 equ 2   ; ┃
SA_RPL3 equ 3   ; ┛

SA_TIG  equ 0   ; ┓TI
SA_TIL  equ 4   ; ┛


; Gate
; Usage: Gate Selector, Offset, DCount, Attr
;   Selector:   dw
;   Offset:     dd
;   DCount:     db
;   Attr:       db
%macro Gate 4
    dw (%2 & 0ffffh)        ; offset1
    dw %1                   ; selector
    dw (%3 & 1fh)|((%4 << 8)& 0ff00h)   ;attr
    dw ((%2 >> 16)& 0ffffh) ; offset2
%endmacro                   ; 8 bytes
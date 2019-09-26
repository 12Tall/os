%include "FAT12.inc"
org 07c00h

BaseOfStack     equ 07c00h  ; 
BaseOfLoader    equ 09000h  ;
OffsetOfLoader  equ 0100h   ;

FAT12Header LABEL_START, "12tall  ", "OrangeS0.02"

LABEL_START:
    mov ax, cs
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, BaseOfStack

    xor ah, ah
    xor dl, dl
    int 13h

; read from Sector 1 only!
    mov word [wSectorNo], IRootSec
LABEL_SEARCH_IN_ROOT_DIR_BEGIN:
    cmp word [wRootDirSizeForLoop], 0   ; read over
    jz  LABEL_NO_LOADERBIN              ; could'nt find LOADER.BIN
    dec word [wRootDirSizeForLoop]      ; wRootDirSizeForLoop--
    mov ax, BaseOfLoader                ; \
    mov es, ax                          ; set params
    mov bx, OffsetOfLoader              ; set
    mov ax, [wSectorNo]                 ; |
    mov cl, 1                           ; read Sector 1
    call ReadSector                     ; /

    mov si, LoaderFileName              ; ds:di -> "LOADER  BIN"
    mov di, OffsetOfLoader              ; es:si -> BaseOfLoader:0100
    cld                                 ; clear direction flag[cld/std]
    mov dx, 10h
LABEL_SEARCH_FOR_LOADERBIN:
    cmp dx, 0                               ; \
    jz  LABEL_GOTO_NEXT_SECTOR_IN_ROOT_DIR  ;   read over then goto next sector
    dec dx                                  ; /
    mov cx, 11                              ; 11 charactors
LABEL_CMP_FILENAME:
    cmp cx, 0                               ;
    jz  LABEL_FILENAME_FOUND                ;
    dec cx
    lodsb                                   ; ds:si -> al then si--; lodsw ds:si -> ax si-=2
    cmp al, byte [es:di]
    jz  LABEL_GO_ON
    jmp LABEL_DIFFERENT                     ; 

LABEL_GO_ON:
    inc di
    jmp LABEL_CMP_FILENAME

LABEL_DIFFERENT:
    and di, 0FFE0h          ; reset di = OffsetOfLoader
    add di, 20h
    mov si, LoaderFileName  ; reset si
    jmp LABEL_SEARCH_FOR_LOADERBIN  ; search again

LABEL_GOTO_NEXT_SECTOR_IN_ROOT_DIR:
	add	word [wSectorNo], 1
	jmp	LABEL_SEARCH_IN_ROOT_DIR_BEGIN

LABEL_NO_LOADERBIN:
    mov dh, 2
    call DisStr
    jmp $

LABEL_FILENAME_FOUND:
    jmp $

; ==============================================================
wRootDirSizeForLoop dw  RootDirSectors  ; Sectors Count of RootDir
                                        ; desc to 0 while loop 
wSectorNo           dw  0               ; index of sector to be read
bOdd                db  0               ; SectorNo is odd
; string
LoaderFileName      db "LOADER  BIN",0  ; LOADER.BIN 

; message
MessageLength		equ	9
BootMessage:		db	"Booting  " 
Message1		    db	"Ready.   " 
Message2		    db	"No LOADER" 
; ==============================================================

; DispStr
DisStr:
    mov ax, MessageLength
    mul dh
    add ax, BootMessage
    mov bp, ax
    mov ax, ds
    mov es, ax
    mov cx, MessageLength
    mov ax, 01301h
    mov bx, 0007h
    mov dl, 0
    int 10h
    ret


; ReadSector
; ---------------------------------------------------------------
; read 'cl' Sectors to es:bx form the 'ax'ed Sector
; ---------------------------------------------------------------
; assume:   SectorNo = X
;                                   ┌ cylinder  = Q >> 1
;       X           ┌ quotient  Q ->|
; ----------------->|               └ header    = Q & 1
; SectorPerTrick(18)└ remainder R ->start sector no = R + 1
ReadSector:
    push    bp
    mov     bp, sp
    sub     esp, 2              ; reserve 2 bytes to save SectorNo to be read
                                ; byte [bp-2]
    mov     byte [bp-2], cl
    push    bx                  ; save bx
    mov     bl, [BPB_SecPerTrk] ; 18
    div     bl                  ; al/18
    inc     ah                  ; \
    mov     cl, ah              ; cl <-- R++
    mov     dh, al              ; dh <-- Q
    shr     al, 1               ; Q >> 1
    mov     ch, al              ;
    and     dh, 1               ; Q & 1
    pop     bx                  ; / 
    ; get cylinder header StartSecNo
    mov     dl, [BS_DrvNum]     ; 0(disk A)
.GoOnReading:
    mov     ah, 2               ; read
    mov     al, byte[bp-2]      ; sectors to be read
    int     13h
    jc .GoOnReading             ; Error during Reading
                                ; will set CF
                                ; loop until read correctly
    add     esp, 2
    pop     bp
    ret                            

times 510-($-$$)    db 0
                    dw 0aa55h


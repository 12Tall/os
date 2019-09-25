
BytsPerSec      equ 512
IFATFirstSec    equ 1
IRootSec        equ 19
RootDirSectors  equ 14          ; root space(Sectors)
IDataSec        equ 33          ; 19+BPB_RootEntCnt * 32 / BPB_BytsPerSec

%macro FAT12Header 3            ; FAT12 first sect
; instrcution                   ; offset    ; length    ; content
jmp short %1                    ; 0         ; 3         ; jmp to entry
nop                             ; 2         ; 1         ; align 4 bytes
; Boot Sector
BS_OEMNAME      DB  %2          ; 3         ; 8         ; OEM string like '12Tall  '
; Boot Parameter Block
BPB_BytsPerSec  DW  512         ; 11        ; 2         ;
BPB_SectPerClus DB  1           ; 13        ; 1         ;
BPB_RsvdSecCnt  Dw  1           ; 14        ; 2         ; reserved section count
BPB_NumFATs     DB  2           ; 16        ; 1         ; number of fat district
BPB_RootEntCnt  DW  224         ; 17        ; 2         ; max file count in root
BPB_TotSec16    DW  2880        ; 19        ; 2         ; totle number of logic sect
BPB_Media       DB  0f0h        ; 21        ; 1         ; media type
BPB_FATSz16     DW  9           ; 22        ; 2         ; sectors per FAT
BPB_SecPerTrk   DW  18          ; 24        ; 2         ; sectors per trick
BPB_NumHeader   DW  2           ; 26        ; 2         ; faces
BPB_HiddSec     DD  0           ; 28        ; 2         ; hidden sectors
BPB_TotSec32    DD  0           ; 32        ; 4         ; number of sectors if BPB_TotSec16 is 0

BS_DrvNum       DB  0           ; 36        ; 1         ; int #13 driver number
BS_Reserved1    DB  0           ; 37        ; 1         ; unused
BS_BootSig      DB  29h         ; 38        ; 1         ; external boot signal
BS_VolID        DD  0           ; 39        ; 4         ; volum index
BS_VolLab       DB  %3          ; 43        ; 11        ; volum label like "VolLabel_11"
BS_FileSysType  DB  "FAT12   "  ; 54        ; 8         ; 
; ... code
; dw 0xaa55
%endmacro   

; =============================================================================
; FAT1
; FAT Entry:index Clus in Data Dustruct
; 0:unused!!!!
; 2n                            2n-1  
; H 76543210 7654 3210 76543210 L
;   FAT Entry 2  |  FAT Entry 1
; last:unused
; FAT Entry: File Next Clus
; 0xFF7: bad Clus
; 0xFF8: last Clus of file
; DirectoryItem.Dir_FstClus=n -> FAT Entry[n] <-+       ; Sec = ClusNum * BPB_SecPerClus
; if FAT Entry[n] = 0xFF8:  last clus of file   |
; if FAT Entry[n] = 0xFF7:  bad clus            |
; else: the next clus index is 8 ---------------+
; -----------------------------------------------------------------------------
; FAT2
; =============================================================================

; =============================================================================
; Directory Item structure
struc DirectoryItem
; field                     ; offset    ; length    ; content
    .DIR_Name       resb    11  ; 0         ; 11        ; FileName
    .DIR_Attr       resb    1   ; 11        ; 1         ; file attr
                    resb    10  ; 12        ; 10        ; reserved
    .DIR_WrtTime    resw    1   ; 22        ; 2         ; last modifed time
    .DIR_WrtDate    resw    1   ; 24        ; 2         ; date
    .DIR_FstClus    resw    1   ; 26        ; 2         ; start clus number
    .DIR_FileSize   resd    1   ; 28        ; 4         ; file size
endstruc
; items should less than BPB_RootEntCnt

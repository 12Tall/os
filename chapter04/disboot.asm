00007C00  EB3C              jmp short 0x7c3e
00007C02  90                nop
00007C03  3132              xor [bp+si],si
00007C05  7461              jz 0x7c68
00007C07  6C                insb
00007C08  6C                insb
00007C09  2020              and [bx+si],ah
00007C0B  0002              add [bp+si],al
00007C0D  0101              add [bx+di],ax
00007C0F  0002              add [bp+si],al
00007C11  E000              loopne 0x7c13
00007C13  40                inc ax
00007C14  0BF0              or si,ax
00007C16  0900              or [bx+si],ax
00007C18  1200              adc al,[bx+si]
00007C1A  0200              add al,[bx+si]
00007C1C  0000              add [bx+si],al
00007C1E  0000              add [bx+si],al
00007C20  0000              add [bx+si],al
00007C22  0000              add [bx+si],al
00007C24  0000              add [bx+si],al
00007C26  2900              sub [bx+si],ax
00007C28  0000              add [bx+si],al
00007C2A  004F72            add [bx+0x72],cl
00007C2D  61                popa
00007C2E  6E                outsb
00007C2F  676553            gs a32 push bx
00007C32  302E3032          xor [0x3230],ch
00007C36  46                inc si
00007C37  41                inc cx
00007C38  54                push sp
00007C39  3132              xor [bp+si],si
00007C3B  2020              and [bx+si],ah
00007C3D  208CC88E          and [si-0x7138],cl
00007C41  D88EC08E          fmul dword [bp-0x7140]
00007C45  D0BC007C          sar byte [si+0x7c00],1
00007C49  31C0              xor ax,ax
00007C4B  30D2              xor dl,dl
00007C4D  CD13              int 0x13
00007C4F  C706A67C1300      mov word [0x7ca6],0x13
00007C55  833EA47C00        cmp word [0x7ca4],byte +0x0
00007C5A  743F              jz 0x7c9b
00007C5C  FF0EA47C          dec word [0x7ca4]
00007C60  B80090            mov ax,0x9000
00007C63  BB0001            mov bx,0x100
00007C66  A1A67C            mov ax,[0x7ca6]
00007C69  B101              mov cl,0x1
00007C6B  E87E00            call 0x7cec
00007C6E  BEA97C            mov si,0x7ca9
00007C71  BF0001            mov di,0x100
00007C74  FC                cld
00007C75  BA1000            mov dx,0x10
00007C78  83FA00            cmp dx,byte +0x0
00007C7B  4A                dec dx
00007C7C  B90B00            mov cx,0xb
00007C7F  83F900            cmp cx,byte +0x0
00007C82  741E              jz 0x7ca2
00007C84  49                dec cx
00007C85  AC                lodsb
00007C86  263A05            cmp al,[es:di]
00007C89  7402              jz 0x7c8d
00007C8B  EB03              jmp short 0x7c90
00007C8D  47                inc di
00007C8E  EBEF              jmp short 0x7c7f
00007C90  83E7E0            and di,byte -0x20
00007C93  83C720            add di,byte +0x20
00007C96  BEA97C            mov si,0x7ca9
00007C99  EBBA              jmp short 0x7c55
00007C9B  B602              mov dh,0x2
00007C9D  E83000            call 0x7cd0
00007CA0  EBFE              jmp short 0x7ca0
00007CA2  EBFE              jmp short 0x7ca2
00007CA4  0E                push cs
00007CA5  0000              add [bx+si],al
00007CA7  0000              add [bx+si],al
00007CA9  4C                dec sp
00007CAA  4F                dec di
00007CAB  41                inc cx
00007CAC  44                inc sp
00007CAD  45                inc bp
00007CAE  52                push dx
00007CAF  2020              and [bx+si],ah
00007CB1  42                inc dx
00007CB2  49                dec cx
00007CB3  4E                dec si
00007CB4  00426F            add [bp+si+0x6f],al
00007CB7  6F                outsw
00007CB8  7469              jz 0x7d23
00007CBA  6E                outsb
00007CBB  672020            and [eax],ah
00007CBE  52                push dx
00007CBF  6561              gs popa
00007CC1  64792E            fs jns 0x7cf2
00007CC4  2020              and [bx+si],ah
00007CC6  204E6F            and [bp+0x6f],cl
00007CC9  204C4F            and [si+0x4f],cl
00007CCC  41                inc cx
00007CCD  44                inc sp
00007CCE  45                inc bp
00007CCF  52                push dx
00007CD0  B80900            mov ax,0x9
00007CD3  F6E6              mul dh
00007CD5  05B57C            add ax,0x7cb5
00007CD8  89C5              mov bp,ax
00007CDA  8CD8              mov ax,ds
00007CDC  8EC0              mov es,ax
00007CDE  B90900            mov cx,0x9
00007CE1  B80113            mov ax,0x1301
00007CE4  BB0700            mov bx,0x7
00007CE7  B200              mov dl,0x0
00007CE9  CD10              int 0x10
00007CEB  C3                ret
00007CEC  55                push bp
00007CED  89E5              mov bp,sp
00007CEF  6683EC02          sub esp,byte +0x2
00007CF3  884EFE            mov [bp-0x2],cl
00007CF6  53                push bx
00007CF7  8A1E187C          mov bl,[0x7c18]
00007CFB  F6F3              div bl
00007CFD  FEC4              inc ah
00007CFF  88C6              mov dh,al
00007D01  D0E8              shr al,1
00007D03  88C5              mov ch,al
00007D05  80E601            and dh,0x1
00007D08  5B                pop bx
00007D09  8A16247C          mov dl,[0x7c24]
00007D0D  B402              mov ah,0x2
00007D0F  8A46FE            mov al,[bp-0x2]
00007D12  CD13              int 0x13
00007D14  72F7              jc 0x7d0d
00007D16  6683C402          add esp,byte +0x2
00007D1A  5D                pop bp
00007D1B  C3                ret
00007D1C  0000              add [bx+si],al
00007D1E  0000              add [bx+si],al
00007D20  0000              add [bx+si],al
00007D22  0000              add [bx+si],al
00007D24  0000              add [bx+si],al
00007D26  0000              add [bx+si],al
00007D28  0000              add [bx+si],al
00007D2A  0000              add [bx+si],al
00007D2C  0000              add [bx+si],al
00007D2E  0000              add [bx+si],al
00007D30  0000              add [bx+si],al
00007D32  0000              add [bx+si],al
00007D34  0000              add [bx+si],al
00007D36  0000              add [bx+si],al
00007D38  0000              add [bx+si],al
00007D3A  0000              add [bx+si],al
00007D3C  0000              add [bx+si],al
00007D3E  0000              add [bx+si],al
00007D40  0000              add [bx+si],al
00007D42  0000              add [bx+si],al
00007D44  0000              add [bx+si],al
00007D46  0000              add [bx+si],al
00007D48  0000              add [bx+si],al
00007D4A  0000              add [bx+si],al
00007D4C  0000              add [bx+si],al
00007D4E  0000              add [bx+si],al
00007D50  0000              add [bx+si],al
00007D52  0000              add [bx+si],al
00007D54  0000              add [bx+si],al
00007D56  0000              add [bx+si],al
00007D58  0000              add [bx+si],al
00007D5A  0000              add [bx+si],al
00007D5C  0000              add [bx+si],al
00007D5E  0000              add [bx+si],al
00007D60  0000              add [bx+si],al
00007D62  0000              add [bx+si],al
00007D64  0000              add [bx+si],al
00007D66  0000              add [bx+si],al
00007D68  0000              add [bx+si],al
00007D6A  0000              add [bx+si],al
00007D6C  0000              add [bx+si],al
00007D6E  0000              add [bx+si],al
00007D70  0000              add [bx+si],al
00007D72  0000              add [bx+si],al
00007D74  0000              add [bx+si],al
00007D76  0000              add [bx+si],al
00007D78  0000              add [bx+si],al
00007D7A  0000              add [bx+si],al
00007D7C  0000              add [bx+si],al
00007D7E  0000              add [bx+si],al
00007D80  0000              add [bx+si],al
00007D82  0000              add [bx+si],al
00007D84  0000              add [bx+si],al
00007D86  0000              add [bx+si],al
00007D88  0000              add [bx+si],al
00007D8A  0000              add [bx+si],al
00007D8C  0000              add [bx+si],al
00007D8E  0000              add [bx+si],al
00007D90  0000              add [bx+si],al
00007D92  0000              add [bx+si],al
00007D94  0000              add [bx+si],al
00007D96  0000              add [bx+si],al
00007D98  0000              add [bx+si],al
00007D9A  0000              add [bx+si],al
00007D9C  0000              add [bx+si],al
00007D9E  0000              add [bx+si],al
00007DA0  0000              add [bx+si],al
00007DA2  0000              add [bx+si],al
00007DA4  0000              add [bx+si],al
00007DA6  0000              add [bx+si],al
00007DA8  0000              add [bx+si],al
00007DAA  0000              add [bx+si],al
00007DAC  0000              add [bx+si],al
00007DAE  0000              add [bx+si],al
00007DB0  0000              add [bx+si],al
00007DB2  0000              add [bx+si],al
00007DB4  0000              add [bx+si],al
00007DB6  0000              add [bx+si],al
00007DB8  0000              add [bx+si],al
00007DBA  0000              add [bx+si],al
00007DBC  0000              add [bx+si],al
00007DBE  0000              add [bx+si],al
00007DC0  0000              add [bx+si],al
00007DC2  0000              add [bx+si],al
00007DC4  0000              add [bx+si],al
00007DC6  0000              add [bx+si],al
00007DC8  0000              add [bx+si],al
00007DCA  0000              add [bx+si],al
00007DCC  0000              add [bx+si],al
00007DCE  0000              add [bx+si],al
00007DD0  0000              add [bx+si],al
00007DD2  0000              add [bx+si],al
00007DD4  0000              add [bx+si],al
00007DD6  0000              add [bx+si],al
00007DD8  0000              add [bx+si],al
00007DDA  0000              add [bx+si],al
00007DDC  0000              add [bx+si],al
00007DDE  0000              add [bx+si],al
00007DE0  0000              add [bx+si],al
00007DE2  0000              add [bx+si],al
00007DE4  0000              add [bx+si],al
00007DE6  0000              add [bx+si],al
00007DE8  0000              add [bx+si],al
00007DEA  0000              add [bx+si],al
00007DEC  0000              add [bx+si],al
00007DEE  0000              add [bx+si],al
00007DF0  0000              add [bx+si],al
00007DF2  0000              add [bx+si],al
00007DF4  0000              add [bx+si],al
00007DF6  0000              add [bx+si],al
00007DF8  0000              add [bx+si],al
00007DFA  0000              add [bx+si],al
00007DFC  0000              add [bx+si],al
00007DFE  55                push bp
00007DFF  AA                stosb

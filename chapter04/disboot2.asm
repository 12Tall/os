00007C00  EB3C              jmp short 0x7c3e
00007C02  90                nop
00007C03  46                inc si
00007C04  6F                outsw
00007C05  7272              jc 0x7c79
00007C07  657374            gs jnc 0x7c7e
00007C0A  59                pop cx
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
00007C49  30E4              xor ah,ah
00007C4B  30D2              xor dl,dl
00007C4D  CD13              int 0x13
00007C4F  C706B17C1300      mov word [0x7cb1],0x13
00007C55  833EAF7C00        cmp word [0x7caf],byte +0x0
00007C5A  744A              jz 0x7ca6
00007C5C  FF0EAF7C          dec word [0x7caf]
00007C60  B80090            mov ax,0x9000
00007C63  8EC0              mov es,ax
00007C65  BB0001            mov bx,0x100
00007C68  A1B17C            mov ax,[0x7cb1]
00007C6B  B101              mov cl,0x1
00007C6D  E88700            call 0x7cf7
00007C70  BEB47C            mov si,0x7cb4
00007C73  BF0001            mov di,0x100
00007C76  FC                cld
00007C77  BA1000            mov dx,0x10
00007C7A  83FA00            cmp dx,byte +0x0
00007C7D  7420              jz 0x7c9f
00007C7F  4A                dec dx
00007C80  B90B00            mov cx,0xb
00007C83  83F900            cmp cx,byte +0x0
00007C86  7425              jz 0x7cad
00007C88  49                dec cx
00007C89  AC                lodsb
00007C8A  263A05            cmp al,[es:di]
00007C8D  7402              jz 0x7c91
00007C8F  EB03              jmp short 0x7c94
00007C91  47                inc di
00007C92  EBEF              jmp short 0x7c83
00007C94  83E7E0            and di,byte -0x20
00007C97  83C720            add di,byte +0x20
00007C9A  BEB47C            mov si,0x7cb4
00007C9D  EBDB              jmp short 0x7c7a
00007C9F  8306B17C01        add word [0x7cb1],byte +0x1
00007CA4  EBAF              jmp short 0x7c55
00007CA6  B602              mov dh,0x2
00007CA8  E83000            call 0x7cdb
00007CAB  EBFE              jmp short 0x7cab
00007CAD  EBFE              jmp short 0x7cad
00007CAF  0E                push cs
00007CB0  0000              add [bx+si],al
00007CB2  0000              add [bx+si],al
00007CB4  4C                dec sp
00007CB5  4F                dec di
00007CB6  41                inc cx
00007CB7  44                inc sp
00007CB8  45                inc bp
00007CB9  52                push dx
00007CBA  2020              and [bx+si],ah
00007CBC  42                inc dx
00007CBD  49                dec cx
00007CBE  4E                dec si
00007CBF  00426F            add [bp+si+0x6f],al
00007CC2  6F                outsw
00007CC3  7469              jz 0x7d2e
00007CC5  6E                outsb
00007CC6  672020            and [eax],ah
00007CC9  52                push dx
00007CCA  6561              gs popa
00007CCC  64792E            fs jns 0x7cfd
00007CCF  2020              and [bx+si],ah
00007CD1  204E6F            and [bp+0x6f],cl
00007CD4  204C4F            and [si+0x4f],cl
00007CD7  41                inc cx
00007CD8  44                inc sp
00007CD9  45                inc bp
00007CDA  52                push dx
00007CDB  B80900            mov ax,0x9
00007CDE  F6E6              mul dh
00007CE0  05C07C            add ax,0x7cc0
00007CE3  89C5              mov bp,ax
00007CE5  8CD8              mov ax,ds
00007CE7  8EC0              mov es,ax
00007CE9  B90900            mov cx,0x9
00007CEC  B80113            mov ax,0x1301
00007CEF  BB0700            mov bx,0x7
00007CF2  B200              mov dl,0x0
00007CF4  CD10              int 0x10
00007CF6  C3                ret
00007CF7  55                push bp
00007CF8  89E5              mov bp,sp
00007CFA  6683EC02          sub esp,byte +0x2
00007CFE  884EFE            mov [bp-0x2],cl
00007D01  53                push bx
00007D02  8A1E187C          mov bl,[0x7c18]
00007D06  F6F3              div bl
00007D08  FEC4              inc ah
00007D0A  88E1              mov cl,ah
00007D0C  88C6              mov dh,al
00007D0E  D0E8              shr al,1
00007D10  88C5              mov ch,al
00007D12  80E601            and dh,0x1
00007D15  5B                pop bx
00007D16  8A16247C          mov dl,[0x7c24]
00007D1A  B402              mov ah,0x2
00007D1C  8A46FE            mov al,[bp-0x2]
00007D1F  CD13              int 0x13
00007D21  72F7              jc 0x7d1a
00007D23  6683C402          add esp,byte +0x2
00007D27  5D                pop bp
00007D28  C3                ret
00007D29  0000              add [bx+si],al
00007D2B  0000              add [bx+si],al
00007D2D  0000              add [bx+si],al
00007D2F  0000              add [bx+si],al
00007D31  0000              add [bx+si],al
00007D33  0000              add [bx+si],al
00007D35  0000              add [bx+si],al
00007D37  0000              add [bx+si],al
00007D39  0000              add [bx+si],al
00007D3B  0000              add [bx+si],al
00007D3D  0000              add [bx+si],al
00007D3F  0000              add [bx+si],al
00007D41  0000              add [bx+si],al
00007D43  0000              add [bx+si],al
00007D45  0000              add [bx+si],al
00007D47  0000              add [bx+si],al
00007D49  0000              add [bx+si],al
00007D4B  0000              add [bx+si],al
00007D4D  0000              add [bx+si],al
00007D4F  0000              add [bx+si],al
00007D51  0000              add [bx+si],al
00007D53  0000              add [bx+si],al
00007D55  0000              add [bx+si],al
00007D57  0000              add [bx+si],al
00007D59  0000              add [bx+si],al
00007D5B  0000              add [bx+si],al
00007D5D  0000              add [bx+si],al
00007D5F  0000              add [bx+si],al
00007D61  0000              add [bx+si],al
00007D63  0000              add [bx+si],al
00007D65  0000              add [bx+si],al
00007D67  0000              add [bx+si],al
00007D69  0000              add [bx+si],al
00007D6B  0000              add [bx+si],al
00007D6D  0000              add [bx+si],al
00007D6F  0000              add [bx+si],al
00007D71  0000              add [bx+si],al
00007D73  0000              add [bx+si],al
00007D75  0000              add [bx+si],al
00007D77  0000              add [bx+si],al
00007D79  0000              add [bx+si],al
00007D7B  0000              add [bx+si],al
00007D7D  0000              add [bx+si],al
00007D7F  0000              add [bx+si],al
00007D81  0000              add [bx+si],al
00007D83  0000              add [bx+si],al
00007D85  0000              add [bx+si],al
00007D87  0000              add [bx+si],al
00007D89  0000              add [bx+si],al
00007D8B  0000              add [bx+si],al
00007D8D  0000              add [bx+si],al
00007D8F  0000              add [bx+si],al
00007D91  0000              add [bx+si],al
00007D93  0000              add [bx+si],al
00007D95  0000              add [bx+si],al
00007D97  0000              add [bx+si],al
00007D99  0000              add [bx+si],al
00007D9B  0000              add [bx+si],al
00007D9D  0000              add [bx+si],al
00007D9F  0000              add [bx+si],al
00007DA1  0000              add [bx+si],al
00007DA3  0000              add [bx+si],al
00007DA5  0000              add [bx+si],al
00007DA7  0000              add [bx+si],al
00007DA9  0000              add [bx+si],al
00007DAB  0000              add [bx+si],al
00007DAD  0000              add [bx+si],al
00007DAF  0000              add [bx+si],al
00007DB1  0000              add [bx+si],al
00007DB3  0000              add [bx+si],al
00007DB5  0000              add [bx+si],al
00007DB7  0000              add [bx+si],al
00007DB9  0000              add [bx+si],al
00007DBB  0000              add [bx+si],al
00007DBD  0000              add [bx+si],al
00007DBF  0000              add [bx+si],al
00007DC1  0000              add [bx+si],al
00007DC3  0000              add [bx+si],al
00007DC5  0000              add [bx+si],al
00007DC7  0000              add [bx+si],al
00007DC9  0000              add [bx+si],al
00007DCB  0000              add [bx+si],al
00007DCD  0000              add [bx+si],al
00007DCF  0000              add [bx+si],al
00007DD1  0000              add [bx+si],al
00007DD3  0000              add [bx+si],al
00007DD5  0000              add [bx+si],al
00007DD7  0000              add [bx+si],al
00007DD9  0000              add [bx+si],al
00007DDB  0000              add [bx+si],al
00007DDD  0000              add [bx+si],al
00007DDF  0000              add [bx+si],al
00007DE1  0000              add [bx+si],al
00007DE3  0000              add [bx+si],al
00007DE5  0000              add [bx+si],al
00007DE7  0000              add [bx+si],al
00007DE9  0000              add [bx+si],al
00007DEB  0000              add [bx+si],al
00007DED  0000              add [bx+si],al
00007DEF  0000              add [bx+si],al
00007DF1  0000              add [bx+si],al
00007DF3  0000              add [bx+si],al
00007DF5  0000              add [bx+si],al
00007DF7  0000              add [bx+si],al
00007DF9  0000              add [bx+si],al
00007DFB  0000              add [bx+si],al
00007DFD  0055AA            add [di-0x56],dl

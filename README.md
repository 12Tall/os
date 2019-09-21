# os  

orange os 读书笔记  

## 启动过程  

- PC 一般一个扇区是512字节  

1. bios 检查软盘0面0磁道1扇区，若以`0xAA55`结尾，则认为是引导扇区  
2. bios 将此512 扇区内容装载到`0000:7c00`处，然后跳转到此处，将控制权交给引导程序  

*这也是为什么要有`org 07c00h`的原因：此命令告诉编译器这段程序要被加载到`07c00h`处*  

## nasm宏命令  

- nasm 编译的机器指令一般是四字节(32 位)对齐的，因为cpu 读取指令时一般是四字节读取，会比较快  
- `[]` 不被`[]`括起的标签或变量名都是地址  

```nasm
foo:
    dw 1        ; 定义标签foo
; foo dw 1      ; 定义变量foo，二者等价
mov ax, foo     ; 将foo 的地址传递给ax
mov ax, [foo]   ; 将1 传递给ax
```  

- `$` 表示当前行地址，`$$` 表示当前节(section)起始的地址  

```nasm
section a aligin=b vstart=c
; a 段名
; b 对齐字节数，默认为4字节，如果段的长度不是4 字节的倍数，则会用00填充
; c 段内汇编地址的开始点，该段内的汇编地址都是从vstart 开始计算的
```

- `times count db 0` 重复count 次db 0  

## Bochs  

Bochs 还是有些坑需要踩的，具体配置可以参考`DLX Linux Demo` 进行配置  

- 路径问题  

```ini
# filename of ROM images
# 可以用$BXSHARE 表示程序默认的安装路径
romimage: file=$BXSHARE/BIOS-bochs-latest
vgaromimage: file=$BXSHARE/VGABIOS-lgpl-latest
# 键盘设置同上
keyboard: keymap=$BXSHARE/keymaps/x11-pc-us.map
```

- 磁盘  

```ini
# what disk images will be used 
floppya: 1_44=boot.img, status=inserted
# floppyb: 1_44=floppyb.img, status=inserted

# hard disk
# ata0: enabled=1, ioaddr1=0x1f0, ioaddr2=0x3f0, irq=14
# ata0-master: type=disk, path="hd10meg.img", cylinders=306, heads=4, spt=17

# choose the boot disk.
boot: floppy
```

- Bochs 自带`bximage` 工具，可以生成磁盘映像，但是要像linux 那样用的话注意添加环境变量  

```powershell
PS D:\prj> bximage
========================================================================
                                bximage
  Disk Image Creation / Conversion / Resize and Commit Tool for Bochs
         $Id: bximage.cc 13069 2017-02-12 16:51:52Z vruppert $
========================================================================

1. Create new floppy or hard disk image
2. Convert hard disk image to other format (mode)
3. Resize hard disk image
4. Commit 'undoable' redolog to base image
5. Disk image info

0. Quit

Please choose one [0] 1

Create image

Do you want to create a floppy disk image or a hard disk image?
Please type hd or fd. [hd] fd

Choose the size of floppy disk image to create.
Please type 160k, 180k, 320k, 360k, 720k, 1.2M, 1.44M, 1.68M, 1.72M, or 2.88M.
 [1.44M]

What should be the name of the image?
[a.img]

Creating floppy image 'a.img' with 2880 sectors

The following line should appear in your bochsrc:
  floppya: image="a.img", status=inserted
(The line is stored in your windows clipboard, use CTRL-V to paste)

Press any key to continue
```  

- win10 无法使用`rawwrite`诶。自己写了一个[工具](https://github.com/12Tall/bin2img)，还挺好用，同样最好也添加环境变量  

- bochs 命令  

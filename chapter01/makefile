# write in linux
# lw:boot.bin
# 	dd if=boot.bin of=/dev/fd0 bs=512 count=1

# write in windows
ww:boot.bin
	bin2img -i boot.bin -o boot.img

# compile
build:boot.asm
	nasm boot.asm -o boot.bin



# write in linux
lw:boot.bin
	dd if=boot.bin of=/dev/fd0 bs=512 count=1

# write in windows
ww:boot.bin
	rawrite2.exe -f boot.bin -d A

# compile
build:boot.asm
	nasm boot.asm -o boot.bin




run: wrtboot bochsrc.bxrc
	bochs -q -f bochsrc.bxrc

debug: wrtboot bochsrc.bxrc
	bochsdbg -q -f bochsrc.bxrc

wrtboot: build
	dd if=../tools/empty.imz of=boot.img bs=512 count=2880
	dd if=boot.bin of=boot.img bs=512 count=1
	
build: boot.asm
	nasm boot.asm -o boot.bin



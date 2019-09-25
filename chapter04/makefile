r: bochsrc.bxrc
	bochs -q -f bochsrc.bxrc

run: wrtboot bochsrc.bxrc
	bochs -q -f bochsrc.bxrc

d: bochsrc.bxrc
	bochsdbg -q -f bochsrc.bxrc

debug: wrtboot bochsrc.bxrc
	bochsdbg -q -f bochsrc.bxrc

wrtboot2: build2
	dd if=../tools/empty.imz of=boot.img bs=512 count=2880
	dd if=boot.bin of=boot.img bs=512 count=1

wrtboot: build
	dd if=../tools/empty.imz of=boot.img bs=512 count=2880
	dd if=boot.bin of=boot.img bs=512 count=1
	
build: boot.asm
	nasm boot.asm -o boot.bin
	
build2: boot2.asm
	nasm boot2.asm -o boot.bin
	
loader2: loader2.asm
	nasm loader2.asm -o LOADER.BIN



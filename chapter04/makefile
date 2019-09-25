
run: bochsrc.bxrc
	bochs -q -f bochsrc.bxrc
debug:ww bochsrc.bxrc
	bochsdbg -q -f bochsrc.bxrc

ww:build
	bin2img -i boot.bin -o boot.img --b

build:boot.asm
	nasm boot.asm -o boot.bin

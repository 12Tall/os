
run:boot.img bochsrc.bxrc
	bochs -q -f bochsrc.bxrc
debug:boot.img bochsrc.bxrc
	bochsdbg -q -f bochsrc.bxrc

ww:boot.bin
	bin2img -i boot.bin -o boot.img --b

build-test1:pmtest1.asm
	nasm pmtest1.asm -o boot.bin

build-test2:pmtest2.asm
	nasm pmtest2.asm -o boot.bin

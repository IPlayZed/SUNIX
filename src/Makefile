# g++ parameters
GPP_PARAMS = -m32 -Wall -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -fpermissive
# assembler parameters
AS_PARAMS = --32
# linker parameters
LD_PARAMS = -melf_i386

# ISO FS
ISO_DIR = iso
ISO_BOOT_DIR = ${ISO_DIR}/boot
ISO_GRUB_DIR = ${ISO_BOOT_DIR}/grub
ISO_GRUB_CFG = ${ISO_GRUB_DIR}/grub.cfg


# compiled files
objectfiles = loader.o kernel.o

# The rule to compile object files from kernel files.
%.o: %.cpp
	g++ ${GPP_PARAMS} -o $@ -c $<
%.o: %.s
	as ${AS_PARAMS} -o $@ $<
	
sunix.bin: linker.ld ${objectfiles}
	ld ${LD_PARAMS} -T $< -o $@ ${objectfiles}

install: sunix.bin
	cp $< ../out

grubinstall: sunix.bin
	sudo cp $< /boot/sunix.bin

sunix.iso: sunix.bin
	mkdir -p ${ISO_GRUB_DIR}
	cp $< ${ISO_BOOT_DIR}
	cp grub.cfg ${ISO_GRUB_DIR}
	grub-mkrescue --output=$@ ${ISO_DIR}
	rm -rf iso
	mv $@ ../out

run: sunix.iso
	qemu-system-i386 ../out/$<
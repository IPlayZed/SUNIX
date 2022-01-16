# g++ parameters
GPP_PARAMS = -m32 -Wall -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
# assembler parameters
AS_PARAMS = --32
# linker parameters
LD_PARAMS = -melf_i386

# compiled files
objectfiles = loader.o kernel.o

# The rule to compile object files from kernel files.
%.o: %.cpp
	g++ ${GPP_PARAMS} -o $@ -c $<
%.o: %.s
	as ${AS_PARAMS} -o $@ $<
	
mykernel.bin: linker.ld ${objectfiles}
	ld ${LD_PARAMS} -T $< -o $@ ${objectfiles}

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin
	mv $< ../out
	mv *.o ../out

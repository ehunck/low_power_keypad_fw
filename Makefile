
TARGET = BLUEPILL_F103C8
TOOLCHAIN = GCC_ARM

all:
	mbed compile -m ${TARGET} -t ${TOOLCHAIN} --profile debug

release:
	mbed compile -m ${TARGET} -t ${TOOLCHAIN} --profile release

clean:
	rm -r BUILD

.PHONY: all clean release
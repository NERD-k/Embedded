CC		= sdcc

all: main.bin

main.bin:main.ihx
		makebin main.ihx > main.bin

main.ihx:main.rel
		$(CC) main.rel

main.rel:main.c
		$(CC) -c main.c

.PHONY:clean
clean:
		rm -r main.lst main.sym main.rel main.asm \
		main.mem main.map main.rst main.lk main.ihx main.bin

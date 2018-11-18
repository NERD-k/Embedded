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
		rm -r ./listings ./objects

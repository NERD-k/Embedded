CC		= sdcc

TOP_DIR := ${CURDIR}
LISTING_DIR := $(TOP_DIR)/listings
OBJECT_DIR := $(TOP_DIR)/objects
OUTPUT_DIR := $(TOP_DIR)/output

init := $(shell mkdir listings objects output)

all: main.bin

main.bin:main.ihx
		makebin main.ihx > main.bin

main.ihx:main.rel
		$(CC) main.rel

main.rel:main.c
		$(CC) -c main.c

.PHONY:clean
clean:
		rm -rf $(LISTING_DIR) $(OBJECT_DIR) $(OUTPUT_DIR)

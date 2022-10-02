
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char *buf1 = malloc(256);
	char *buf2 = malloc(512);
	char *buf3 = malloc(1024);
	char *top, *aftertop;

	printf("buf1: %08X %08X\n", *(int*)(buf1-8), *(int*)(buf1-4));
	printf("buf2: %08X %08X\n", *(int*)(buf2-8), *(int*)(buf2-4));
	printf("buf3: %08X %08X\n", *(int*)(buf3-8), *(int*)(buf3-4));

	// Get starting position of the top chunk by first getting to pointer to the
	// chunk of buf3, and then adding the size of the chunk to the pointer.
	top = buf3 - 8;
	// Remember clear last 3 bits!
	top += (*(int*)(buf3 - 4) & 0xFFFFFFF8);

	printf("top:  %08X %08X\n", *(int*)(top), *(int*)(top+4));

	// Get a pointer to the memory *after* the top chunk
	aftertop = top + (*(int*)(top + 4) & 0xFFFFFFF8);
	printf("aftertop at %p = %p + 0x%X\n", aftertop, top, (*(int*)(top + 4) & 0xFFFFFFF8));

	// This printf will most likely segfault because it attempts to read from
	// unallocated memory (i.e., it's an address *after* the heap)
	printf("aftertop:  %08X %08X\n", *(int*)(aftertop), *(int*)(aftertop + 4));
}

/*
 ============================================================================
 Name        : Bitshift_test.c
 Author      : Jakob
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MASK(x) (1<<(x))

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

int main(void) {
	uint32_t memory = 0x0000;

	printf("\nOriginal memory: 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

	memory |= MASK(0);
	printf("\nMemory after |= MASK(0): 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

	memory &= ~MASK(0);
	printf("\nMemory after &= ~MASK(0): 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

	memory |= MASK(1);
	printf("\nMemory after |= MASK(1): 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

	memory = 0x000F;
	printf("\n\n\nMemory set to 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

	memory |= MASK(6);
	printf("\nMemory after |= MASK(6): 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

	memory |= MASK(7);
	printf("\nMemory after |= MASK(7): 0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(memory));

}

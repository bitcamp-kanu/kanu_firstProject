#include <stdio.h>


void main()
{
	unsigned char val1 = 0x05, val2 = 0x07, val3 = 0;
	int a, b;
	a = val1 << 4;
	b = a | val2;
	val3 = b;
	printf("%x", val3);
		return 0;
}




















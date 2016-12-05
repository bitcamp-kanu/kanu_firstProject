#include <stdio.h>

void main()
{
	//3*8/4=3*(2^3)/(2^2)

	int a = 3 << 3 >> 2;
	printf("%d\n",a);
	return 0;
}
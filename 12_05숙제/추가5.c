#include<stdio.h>

int main() {
	unsigned char val1, val2, val3, buf;


	val1 = 0x57; //초기값


	val2 = val1 >> 4; //왼쪽으로 4번 쉬프트하여 7을 버림


	val3 = val1 & 0xf; //

	printf("val2 = %x\n     val3 = %x\n", val2, val3);
	
}
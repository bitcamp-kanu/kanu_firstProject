#include<stdio.h>

int main() {
	unsigned char val1, val2, val3, buf;


	val1 = 0x57; //�ʱⰪ


	val2 = val1 >> 4; //�������� 4�� ����Ʈ�Ͽ� 7�� ����


	val3 = val1 & 0xf; //

	printf("val2 = %x\n     val3 = %x\n", val2, val3);
	
}
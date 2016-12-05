#include<stdio.h>

void main()
{
	int a;
	int b;
	printf("나이를 입력해주세요:");
	scanf("%d",&a);
		b = (a - 1) * 365 * 3000*3;
		printf("%d원입니다.", b);
		return 0;
}
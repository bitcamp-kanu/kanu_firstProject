#include<stdio.h>
int main()
{
	int i;
	printf("������ �Է��ϼ���.\n");
	scanf("%d", &i);
	i = ~i;  
	i = i + 1;
	printf("%d \n", i);
	return 0;
}
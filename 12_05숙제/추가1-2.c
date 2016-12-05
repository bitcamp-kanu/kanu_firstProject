#include<stdio.h>
int main()
{
	int i;
	printf("정수를 입력하세요.\n");
	scanf("%d", &i);
	i = ~i;  
	i = i + 1;
	printf("%d \n", i);
	return 0;
}
#include <stdio.h>

int Add(int n1,int n2)

//변수의 의미 공간,값
//int a = 10;	//공간으로써 사용
//int temp = a; //  값으로서 사용.
void main()
{
	int sum = 0;
	int a = 10, b=20;
	int temp = a;
	int c = 0x123456789;
	int* ptrSum = &sum;
	

	

	int* ptrA = &a;
	int* ptrB = &b;


	printf("%d/n",sum);
	sum = Add(a,b);
	*ptrSum = *ptrA+*ptrB;

	

}
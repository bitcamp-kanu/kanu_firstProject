#include <stdio.h>

int Add(int n1,int n2)

//������ �ǹ� ����,��
//int a = 10;	//�������ν� ���
//int temp = a; //  �����μ� ���.
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
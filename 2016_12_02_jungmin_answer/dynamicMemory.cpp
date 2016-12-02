#include "dynamicMemory.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//02 �����Ҵ�. 2.1. ����ڷκ��� � ���ڿ� ������ ���� �Է�
//		������ŭ char �����Ҵ�
//		���ڿ� �Է�
//		ȭ�����
//		�����Ҵ� ����
int InputText()
{
	const int bufferSize = 255; //�Ѵܾ��� �ִ� ũ��� 255�� ���� �Ѵ�.

	char buff[bufferSize];
	char** pStrs = NULL;
	int nSize = 0;
	int inputStrLen = 0;
	printf("������ �ܾ��� ������ �Է� �ϼ���. "); 
	scanf("%d" , &nSize);
	

	pStrs = (char**)malloc(sizeof(char*)*nSize);
	for(int i = 0 ; i < nSize ; i++)
	{
		printf("�ܾ �Է� �ϼ���. "); 
		scanf("%s" , &buff);
		inputStrLen = strlen(buff);
		*(pStrs+i) = (char*)malloc(sizeof(char*)*inputStrLen + 1);
		strcpy(*(pStrs+i),buff);
		fflush(stdin);
	}

	printf("�Էµ� �ܾ ��� �մϴ�."); 
	getchar();

	for(int i = 0 ; i < nSize ; i++)
	{
		printf("%d ��° �Է� == >%s\n" ,i,*(pStrs+i));
		//free(*(pStrs+i));
		//*(pStrs+i) = NULL;
		free(pStrs[i]);
		pStrs[i] = NULL;
	}
	free(pStrs);
	
	getchar();
	return 0;
}
//2.2. �������߿� 3���� �����Ҵ����� ���� �����ϰ� ����ϼ���.
//3 6 9 12 15 18 21 14 27
int Gugudan3Dan()
{
	int** ppArry  = NULL;
	ppArry = (int**)malloc(sizeof(int)*2*8);
	memset(ppArry,0x03,sizeof(int)*2*8);

	int * data =(int*)ppArry;
	for(int row = 0; row < 8; row++)
	{
		for(int col = 0; col < 2; col++)
		{
			if(col == 0)
			{
				*(data +  (2 * row) + col) = 3;
				
			}
			else
			{
				*(data +  (2 * row) + col) = row + 2;
			}
		}
	}

	int x,y;

	for(int row = 0; row < 8; row++)
	{
		x = *(data +  (2 * row) + 0);
		y = *(data +  (2 * row) + 1);
		printf("%d * %d = %d \n",x,y , x*y);
	}
	getchar();
	free(ppArry);
	ppArry = NULL;
	return 0;
}


// 2.3. korea -> aerok �����迭�� �ϼ���.
#define _KOREA_SZIE_ 6
int Convert()
{
	char* pStr1 = NULL;
	char* pStr2 = NULL;

	pStr1 = (char*)malloc(sizeof(char)*6);
	pStr2 = (char*)malloc(sizeof(char)*6);

	memset(pStr1,0x00,sizeof(char)*6);
	memset(pStr2,0x00,sizeof(char)*6);
	strcpy(pStr1 ,"korea");
	int len = strlen(pStr1);

	for(int i = 0;i < len; i++ )
	{
		pStr2[len-i-1] = pStr1[i];
	}

	printf("%s\n", pStr1);
	printf("%s\n", pStr2);

	free(pStr1); pStr1 = NULL;
	free(pStr2); pStr2 = NULL;

	getchar();
	return 0;
}
//2.4. ����ü���̿��Ѽ���ó��.c �� �л����� ����ڷ� ���� �Է¹޾�
//     �����迭�� �Ҵ��ϴ� ������� �ٲټ���
void dynamic_main()
{
	//InputText();
	//Gugudan3Dan();
	Convert();
}
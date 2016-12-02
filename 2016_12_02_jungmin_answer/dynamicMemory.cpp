#include "dynamicMemory.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//02 동적할당. 2.1. 사용자로부터 몇개 문자열 받을지 정수 입력
//		정수만큼 char 동적할당
//		문자열 입력
//		화면출력
//		동적할당 해제
int InputText()
{
	const int bufferSize = 255; //한단어의 최대 크기는 255로 설정 한다.

	char buff[bufferSize];
	char** pStrs = NULL;
	int nSize = 0;
	int inputStrLen = 0;
	printf("생성할 단어의 갯수를 입력 하세요. "); 
	scanf("%d" , &nSize);
	

	pStrs = (char**)malloc(sizeof(char*)*nSize);
	for(int i = 0 ; i < nSize ; i++)
	{
		printf("단어를 입력 하세요. "); 
		scanf("%s" , &buff);
		inputStrLen = strlen(buff);
		*(pStrs+i) = (char*)malloc(sizeof(char*)*inputStrLen + 1);
		strcpy(*(pStrs+i),buff);
		fflush(stdin);
	}

	printf("입력된 단어를 출력 합니다."); 
	getchar();

	for(int i = 0 ; i < nSize ; i++)
	{
		printf("%d 번째 입력 == >%s\n" ,i,*(pStrs+i));
		//free(*(pStrs+i));
		//*(pStrs+i) = NULL;
		free(pStrs[i]);
		pStrs[i] = NULL;
	}
	free(pStrs);
	
	getchar();
	return 0;
}
//2.2. 구구단중에 3단을 동적할당으로 값을 대입하고 출력하세요.
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


// 2.3. korea -> aerok 동적배열로 하세요.
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
//2.4. 구조체를이용한성적처리.c 중 학생수를 사용자로 부터 입력받아
//     동적배열을 할당하는 방식으로 바꾸세요
void dynamic_main()
{
	//InputText();
	//Gugudan3Dan();
	Convert();
}
#include "BlackBox.h"
#include "stdlib.h"
#include "stdio.h"
//#include "windows.h"
//#include <unistd.h>


//#include <unistd.h>
//#include <unistd.h>

//Reverse 를 사용하여 파일을 Encode,Decode 한다.
int ReverseEncodeDecode(char* srcPath,char* tarPath)
{
	FILE* pFScr = NULL;
	FILE* pFTar = NULL;

	pFScr = fopen(srcPath,"r");
	if(pFScr == NULL)
	{
		printf("파일 읽기에 실패하였습니다. [%s]",srcPath);
		return -1;
	}
	pFTar = fopen(tarPath,"w");
	if(pFTar == NULL)
	{
		printf("파일 읽기에 실패하였습니다. [%s]",tarPath);
		return -1;
	}

	char ch;
	int nCnt = 0;
	while(true)
	{
		if( feof( pFScr ) != 0 )
			break;
		ch = fgetc(pFScr);
		fputc(~ch,pFTar);
		 nCnt++;
	}
	fclose(pFScr);
	pFScr = NULL;
	fclose(pFTar);
	pFTar = NULL;
	return nCnt;
}
//Exclusive 를 사용하여 파일을 Encode,Decode 한다.
int ExclusiveEncodeDecode(char* srcPath,char* tarPath,char key)
{
	FILE* pFScr = NULL;
	FILE* pFTar = NULL;

	pFScr = fopen(srcPath,"r");
	if(pFScr == NULL)
	{
		printf("파일 읽기에 실패하였습니다. [%s]",srcPath);
		return -1;
	}
	pFTar = fopen(tarPath,"w");
	if(pFTar == NULL)
	{
		printf("파일 읽기에 실패하였습니다. [%s]",tarPath);
		return -1;
	}

	char ch;
	int nCnt = 0;
	while(true)
	{
		if( feof( pFScr ) != 0 )
			break;
		ch = fgetc(pFScr);
		fputc((ch^key),pFTar);
		 nCnt++;
	}

	fclose(pFScr);
	pFScr = NULL;
	fclose(pFTar);
	pFTar = NULL;
	return nCnt;

	return nCnt;
}
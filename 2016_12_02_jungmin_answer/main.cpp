#include <stdio.h>
#include "turboc.h"
#include "starStack.h"
#include "dynamicMemory.h"
#include "grade.h"
#include "BlackBox.h"

// -revT [source] [target]       -반전을 이용한 암호 복호화
// -excT [source] [target] [key] -XOR 을 이용한 암호 복호화
void main(int argc,char** argv)
{

	char* strSource;
	char* strTarget;
	char  key;
	int nCnt = 0; //복호 암호화된 문자 겟수.
	if(argc > 1) //
	{
		char* cmd = *(argv+1);
		if(strcmp(cmd,"-rev") == 0 || strcmp(cmd,"-revT") == 0)
		{
			if(argc == 4)
			{
				strSource = *(argv+2);
				strTarget = *(argv+3);	
				printf("(REV)암호또는복호화 작업을 시작 합니다.\n");
				printf("Soruce: [%s], Target: [%s]",strSource,strTarget);
				nCnt = ReverseEncodeDecode(strSource,strTarget);
				printf("암호문자(REV) 갯수 [%d].\n",nCnt);
				if(strlen(cmd) == 5)
				{
					nCnt = ReverseEncodeDecode(strTarget,"REV복호.txt");
					printf("복호문자(REV) 갯수 [%d].\n",nCnt);
				}
			}
			else 
			{
				printf("명령줄 인수가 잘못 되었습니다.");
			}
		}
		else if(strcmp(cmd,"-exc") == 0 || strcmp(cmd,"-excT") == 0)
		{
			if(argc == 5)
			{
				strSource = *(argv+2);
				strTarget = *(argv+3);
				key = (*(argv+4))[0];
				printf("(XOR)암호또는복호화 작업을 시작 합니다.\n");
				printf("Soruce: [%s], Target: [%s] ,Key: [%c]",strSource,strTarget,key);
				nCnt = ExclusiveEncodeDecode(strSource,strTarget,key);
				printf("암호(XOR) 문자 갯수 [%d].\n",nCnt);
				if(strlen(cmd) == 5)
				{
					nCnt = ExclusiveEncodeDecode(strTarget,"XOR복호.txt",key);
					printf("복호(XOR) 문자 갯수 [%d].\n",nCnt);
				}
			}
			else
			{
				printf("명령줄 인수가 잘못 되었습니다.");
			}
			getchar();
		}
		
	}
	//main_star();
	//dynamic_main();
	//grade_main();
}
#include <stdio.h>
#include "turboc.h"
#include "starStack.h"
#include "dynamicMemory.h"
#include "grade.h"
#include "BlackBox.h"

// -revT [source] [target]       -������ �̿��� ��ȣ ��ȣȭ
// -excT [source] [target] [key] -XOR �� �̿��� ��ȣ ��ȣȭ
void main(int argc,char** argv)
{

	char* strSource;
	char* strTarget;
	char  key;
	int nCnt = 0; //��ȣ ��ȣȭ�� ���� �ټ�.
	if(argc > 1) //
	{
		char* cmd = *(argv+1);
		if(strcmp(cmd,"-rev") == 0 || strcmp(cmd,"-revT") == 0)
		{
			if(argc == 4)
			{
				strSource = *(argv+2);
				strTarget = *(argv+3);	
				printf("(REV)��ȣ�Ǵº�ȣȭ �۾��� ���� �մϴ�.\n");
				printf("Soruce: [%s], Target: [%s]",strSource,strTarget);
				nCnt = ReverseEncodeDecode(strSource,strTarget);
				printf("��ȣ����(REV) ���� [%d].\n",nCnt);
				if(strlen(cmd) == 5)
				{
					nCnt = ReverseEncodeDecode(strTarget,"REV��ȣ.txt");
					printf("��ȣ����(REV) ���� [%d].\n",nCnt);
				}
			}
			else 
			{
				printf("����� �μ��� �߸� �Ǿ����ϴ�.");
			}
		}
		else if(strcmp(cmd,"-exc") == 0 || strcmp(cmd,"-excT") == 0)
		{
			if(argc == 5)
			{
				strSource = *(argv+2);
				strTarget = *(argv+3);
				key = (*(argv+4))[0];
				printf("(XOR)��ȣ�Ǵº�ȣȭ �۾��� ���� �մϴ�.\n");
				printf("Soruce: [%s], Target: [%s] ,Key: [%c]",strSource,strTarget,key);
				nCnt = ExclusiveEncodeDecode(strSource,strTarget,key);
				printf("��ȣ(XOR) ���� ���� [%d].\n",nCnt);
				if(strlen(cmd) == 5)
				{
					nCnt = ExclusiveEncodeDecode(strTarget,"XOR��ȣ.txt",key);
					printf("��ȣ(XOR) ���� ���� [%d].\n",nCnt);
				}
			}
			else
			{
				printf("����� �μ��� �߸� �Ǿ����ϴ�.");
			}
			getchar();
		}
		
	}
	//main_star();
	//dynamic_main();
	//grade_main();
}
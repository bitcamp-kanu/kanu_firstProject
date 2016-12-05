#include "fileIo.h"
#include <stdio.h>
#include <string.h>



#define _FILE_NAME_ "mystory.txt"

#define _FILE_PHONE_NAME_ "phone.txt"

#define INPUT_FORMAT "%s %s %s %s"
#define OUTPUT_FORMAT "%s,%s,%s,%s\n"

User rgTUsers[_NODE_MAX_CNT_] = {0};
char buffer[_BUFF_SIZE_] = {0};
int iUserCnt = 0; 
/*
1. mystory.txt������ �����ؼ�  �̸�, ����, ��ȭ��ȣ�� �����ϼ��� ������ ���´�
# �̸� : ȫ�浿
# ���� : 24
# ��ȭ��ȣ : 010-1111-2222
*/
int HomeWork01()
{
	FILE* pFile = fopen(_FILE_NAME_,"w");
	if(pFile == NULL)
	{
		printf("���Ͽ��⿡ �����Ͽ����ϴ�.");
		return -1;
	}
	fputs("# �̸� : ȫ�浿\n",pFile);
	fputs("# ���� : 24\n",pFile);
	fputs("# ��ȭ��ȣ : 010-1111-2222\n",pFile);
	
	fclose(pFile);
	pFile = NULL;

	return 1;
}

/*
2. 1�����Ͽ� �����͸� �߰��ϼ���.
# ��ܸԴ� ���� : «��, ������
# ��� : �౸
*/
int HomeWork02()
{
	FILE* pFile = fopen(_FILE_NAME_,"a");
	if(pFile == NULL)
	{
		printf("���Ͽ��⿡ �����Ͽ����ϴ�.");
		return -1;
	}
	fputs("# ��ܸԴ� ���� : «��, ������\n",pFile);
	fputs("# ��� : �౸\n",pFile);
	
	fclose(pFile);
	pFile = NULL;
	return 1;
}

//3. 2���� �Ϸ��� �� ������ �а� ����ϼ���.
int HomeWork03(char* szFileName)
{
	FILE* pFile = fopen(szFileName,"r");
	char buffer[_BUFF_SIZE_];

	while(!feof(pFile))
	{
		//buffer[0] = 0x00;
		fgets(buffer,_BUFF_SIZE_,pFile);
		printf(buffer);
	}

	fclose(pFile);
	pFile = NULL;

}

//4. �ּҷ� ������ �����ϰ� ����� �Է��� �޾Ƽ�
//  �߰�, ����, ���� �غ�����
//	�̸�,����,���,�ּ�
//	ex)
//	ȫ�浿,024,Ȱ��,�ݰ���
//	�Ӳ���,033,�Ŀ�,������
//	����,036,����,����
//	������,021,�ڽ�����,��������
int HomeWork04()
{
	int i = 0;
	int ilen = 0;
	int iTolLen = 0;
	int bExit = 0;
	int iMatch = 0;
	char ch;
	User tUser;	
	FILE* pFile = NULL;	

	_readUsers(); // ���� ����Ǿ� �ִ� ������ �����о�´�. 

	while(bExit == 0)
	{
		printf("�޴��� ���� �ϼ���.\n");
		printf("�߰�('1') , ����('2') , ����('3') , ����('0')\n");
		ch = getch();
		switch(ch)
		{
		case '0':
			bExit = 1;
			break;
		case '1': //�ű�			
			memset(&tUser,0x00,sizeof(User));
			memset(&buffer,0x00,sizeof(char)*_BUFF_SIZE_);
			
			printf("�̸� ���� ��� �ּҸ� �Է��ϼ���.\n");
			scanf(INPUT_FORMAT,tUser.szName,tUser.szAge,tUser.szHobby,tUser.szAddr);
			rgTUsers[iUserCnt] = tUser;
			iUserCnt++;

			_writeUsers(); //�����͸� �ٷ� �����Ѵ�.
			pFile = NULL;
			break;
		case '2': //����. 
			iMatch = 0;
			memset(&tUser,0x00,sizeof(User));
			memset(&buffer,0x00,sizeof(char)*_BUFF_SIZE_);
			printf("������ �̸��� ���� �ϼ���.\n");
			scanf("%s",buffer);
			
			for(i = 0 ; i < iUserCnt ;i++)
			{
				if(strcmp(rgTUsers[i].szName,buffer) == 0 )
				{
					printf("������ �̸��� �Է��ϼ���\n");
					scanf("%s",buffer);
					strcpy(rgTUsers[i].szName,buffer);
				}	
			}
			_writeUsers();
			break;
		case '3':
			iMatch = 0;
			memset(&tUser,0x00,sizeof(User));
			memset(&buffer,0x00,sizeof(char)*_BUFF_SIZE_);
			printf("������ �̸��� ���� �ϼ���.\n");
			scanf("%s",buffer);

			for(i = 0 ; i < iUserCnt ;i++)
			{
				if(strcmp(rgTUsers[i].szName,buffer) == 0)
				{
					rgTUsers[i].bDel = 1;
				}	
			}
			_writeUsers();
			break;
		default:

			break;
		}
	}
}


//���Ͽ��� User �� �о�´�.
int _readUsers()
{	
	FILE* pFile = NULL;
	iUserCnt = 0;
	pFile = fopen(_FILE_PHONE_NAME_,"r");			
	if(pFile != NULL)
	{
		while(feof(pFile) == 0)
		{
			fgets(buffer,_BUFF_SIZE_,pFile);
			rgTUsers[iUserCnt] = bufferTOUser(buffer);
			iUserCnt++;
		}

		fclose(pFile);
	}
	
}
int _writeUsers()
{
	FILE* pFile = NULL;
	int i = 0;
	pFile = fopen(_FILE_PHONE_NAME_,"w");			
	for(i = 0 ; i < iUserCnt ;i++)
	{
		if(rgTUsers[i].bDel == 0)
		{
			sprintf(buffer,OUTPUT_FORMAT,rgTUsers[i].szName,rgTUsers[i].szAge,rgTUsers[i].szHobby,rgTUsers[i].szAddr);
			fputs(buffer,pFile);
		}
	}
	fclose(pFile);
	//iUserCnt �� ����ÿ� �ʱ�ȭ �Ѵ�.
}


User bufferTOUser(char* buffer)
{
	int i;
	int ilen = 0,cntComma = 0 , idxComma = 0;	
	User tUser = {0};

	ilen = strlen(buffer);
	idxComma = 0;
	for(i = 0; i < ilen ; i++)
	{
		if(buffer[i] == ',')
		{
			cntComma++;
			idxComma = i + 1; //, ��ġ�� ���� ��Ų��. 
		}

		if(buffer[i] != ',')
		{
			if(cntComma == 0)
			{
				tUser.szName[i -idxComma] = buffer[i];	
			}
			else if(cntComma == 1)
			{
				tUser.szAge[i-idxComma ] = buffer[i];
			}
			else if(cntComma == 2)
			{
				tUser.szHobby[i -idxComma ] = buffer[i];
			}
			else
			{
				tUser.szAddr[i -idxComma ] = buffer[i];
			}	
		}
		
	}
	return tUser;
}
int fileIo_Main()
{
	//HomeWork01();
	//HomeWork02();
	//HomeWork03(_FILE_NAME_);

	HomeWork04();

	getchar();
	return 1;
};

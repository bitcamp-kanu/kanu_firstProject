#include "grade.h"
#include <stdio.h>
#include <stdlib.h> //malloc �� scanf �� ����ϱ� ���Ͽ� �߰�.
/*
	�´� ����� ���°� ���� ������.
	������ ���� �κ��� ���� Ȯ���� ���ذ� �ʵ�.
	�� -> �����ڰ� �ƴϰ� . �����ڸ� ���°� ������ ���� �ѹ��� �ʿ���.
	(*pTmpGrd).name) ,pTmpGrd->name  �α����� ���� ���� �˰� ���⵵ ��.
*/


void grade_main()
{
	char* subjects[SUBJECTS]={"����", "����", "����"};
	//Grade grd[STUDENTS];
	Grade* pGrd = NULL;	//�Է¹��� �л��� �Ҵ��� ����.
	int i=0, j=0;
	int nStudends = 0; //Scanf ���� �л����� �Է� ���� ����

	printf("������ �Է��� �л����� �Է� �ϼ���.");
	scanf("%d",&nStudends);

	pGrd = (Grade*)malloc(sizeof(Grade)*nStudends); //�Է� ��������ŭ �迭�� �Ҵ�.

	
	// 1) ���� �Է� 
	for(i = 0; i < nStudends ;i++) //STUDENTS nStudends  ����.
	{
		Grade* pTmpGrd = (pGrd+i);
		printf("*********************%d ��° �л�*********************\n", i+1);
		printf("�̸� : ");
		
		//�Ʒ� �α����� ���� ����.
		//scanf("%s", (*pTmpGrd).name); 
		scanf("%s", pTmpGrd->name);

		for(j=0;j<SUBJECTS;j++)
		{
			printf("%s: ", subjects[j]);
			scanf("%d", &((*pTmpGrd).score[j]));
		}
	}

	// 2) ���� ���
	for(i = 0 ; i < nStudends ;i++)
	{
		Grade* pTmpGrd = (pGrd+i);
		
		//�Ѵ� ���� ����.
		//(*pTmpGrd).total=0;
		pTmpGrd->total=0;
		for(j=0;j<SUBJECTS;j++)
		{
			//�Ѵ� ���� ����.
			//(*pTmpGrd).total += (*pTmpGrd).score[j]; 
			pTmpGrd->total += pTmpGrd->score[j];
		}
		(*pTmpGrd).average = (double)((*pTmpGrd).total/SUBJECTS);
	}

	// 3) ���� ���
	printf("--------------------------------------------------\n");
	printf("�̸�\t| ����\t| ����\t| ����\t| ����\t| ���\n");
	for(i=0;i<nStudends;i++)
	{
		Grade* pTmpGrd = (pGrd+i);

		printf("%s\t| ", pTmpGrd->name);
		for(j=0;j<SUBJECTS;j++)
		{
			printf("%d\t| ", pTmpGrd->score[j]);
		}
		printf("%d\t| ", pTmpGrd->total);
		printf("%0.2lf\n", pTmpGrd->average);
	}
	//fflush(stdin);
	printf("--------------------------------------------------\n");
	getchar();
}
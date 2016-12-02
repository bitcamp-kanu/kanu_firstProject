#include "grade.h"
#include <stdio.h>
#include <stdlib.h> //malloc 와 scanf 를 사용하기 위하여 추가.
/*
	맞는 결과가 나온곳 같긴 하지만.
	포인터 연산 부분은 아직 확실히 이해가 않됨.
	외 -> 연산자가 아니고 . 연산자를 쓰는게 만는지 정리 한번이 필요함.
	(*pTmpGrd).name) ,pTmpGrd->name  두구문다 문제 없음 알것 같기도 함.
*/


void grade_main()
{
	char* subjects[SUBJECTS]={"국어", "영어", "수학"};
	//Grade grd[STUDENTS];
	Grade* pGrd = NULL;	//입력받은 학생을 할당할 변수.
	int i=0, j=0;
	int nStudends = 0; //Scanf 에서 학생수를 입력 받을 변수

	printf("성적을 입력할 학생수를 입력 하세요.");
	scanf("%d",&nStudends);

	pGrd = (Grade*)malloc(sizeof(Grade)*nStudends); //입력 받은수반큼 배열을 할당.

	
	// 1) 성적 입력 
	for(i = 0; i < nStudends ;i++) //STUDENTS nStudends  변경.
	{
		Grade* pTmpGrd = (pGrd+i);
		printf("*********************%d 번째 학생*********************\n", i+1);
		printf("이름 : ");
		
		//아래 두구문다 문제 없음.
		//scanf("%s", (*pTmpGrd).name); 
		scanf("%s", pTmpGrd->name);

		for(j=0;j<SUBJECTS;j++)
		{
			printf("%s: ", subjects[j]);
			scanf("%d", &((*pTmpGrd).score[j]));
		}
	}

	// 2) 성적 계산
	for(i = 0 ; i < nStudends ;i++)
	{
		Grade* pTmpGrd = (pGrd+i);
		
		//둘다 문제 없음.
		//(*pTmpGrd).total=0;
		pTmpGrd->total=0;
		for(j=0;j<SUBJECTS;j++)
		{
			//둘다 문제 없음.
			//(*pTmpGrd).total += (*pTmpGrd).score[j]; 
			pTmpGrd->total += pTmpGrd->score[j];
		}
		(*pTmpGrd).average = (double)((*pTmpGrd).total/SUBJECTS);
	}

	// 3) 성적 출력
	printf("--------------------------------------------------\n");
	printf("이름\t| 국어\t| 영어\t| 수학\t| 총점\t| 평균\n");
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
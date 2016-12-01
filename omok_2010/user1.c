#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _eNode 
{
	NONE = -1,
	WHITE	=  0,
	BLACK   = 1,
	TOPLEFT = 2,
	TOP = 3,
	TOPRIGHT = 4,
	LEFT = 5,
	CENTER  = 6,
	RIGHT = 7,
	BOTLEFT = 8,
	BOTRIGHT = 9,
	//- 이하는 --
	ALLDOL, //전체 돌수.
};

typedef enum _eNode  eNode;
struct _dol
{
	int row;
	int col;
	int weigth; //가중치
	eNode node;
	int indxe; //배열의 인덱스.
};

typedef struct _dol Dol;

Dol blackdols[15*15];
Dol whitedols[15*15];

int weigthBlackPan[15][15] = {0};
int weigthWhitePan[15][15] = {0};

int GetDolCount(int pan[][15],eNode node)
{	
	int count = 0;
	int row,col;
	for(row = 0; row < 15; row++)
	{
		for(col = 0; col < 15; col++)
		{
			if(node == ALLDOL)
			{
				count++;
			}
			else 
			{
				if(pan[row][col] == node)
				{
					count++;
				}
			}	
		}
	}
	return count;
}

//내 돌 위치의 목록을 생성 한다.
int GetDolLoc(int pan[][15], eNode node)
{
	//동적 할당이 싫어서 
	int cnt = 0;
	int row,col;
	for(row = 0 ; row < 15 ; row++)
	{
		for(col = 0; col < 15; col++)
		{
			if(pan[row][col] == node)
			{
				if(node == BLACK)
				{
					blackdols[cnt].row = row;
					blackdols[cnt].col = col;
					cnt++;
				}
				else if(node == WHITE)
				{

					whitedols[cnt].row = row;
					whitedols[cnt].col = col;
					cnt++;
				}
			}
		}
	}	
	return cnt;
}
void user1(int pan[][15],int* x,int* y)
{

	static int ix;
	static int iy;
	int dolCnt = 0;
	static eNode dol = NONE; //처음 실행시 한번만 설정.i
	int blackCnt = 0;
	int whiteCnt = 0;


	if(pan == NULL) //처음 실행.
	{
		dol = (eNode)(*x);
	}
	dolCnt = GetDolCount(pan,dol);

	
	blackCnt = GetDolCount(pan,BLACK);
	whiteCnt = GetDolCount(pan,WHITE);

	if(dol == BLACK) //선공 이면
	{
		switch(dolCnt)
		{
		case 0:	 //첫수이면 중앙에 넣는다.
			*x = 17;
			*y = 17;
			break;
		case 1:			//둘째수
			//오른쪽 부터 돌면서 넣는다.


			break;
		case 2:			//세째수. 
			break;
		case 3:
			break;		
		}
	}
	



	//if( pan == NULL ){
	//	i_color = *x;
	//	iy = ix = 8;		
	//}else{
	//	++ix;
	//	--iy;
	//	*x = ix;
	//	*y = iy;
	//}
}

//가중치를 계산한다.
int MakeWeigth(int pan[][15],eNode node)
{
	int blackCount, whiteCount;
	int i ,j , cnt;

	Dol doll[5] = {{-1,-1}};

	blackCount = GetDolLoc(pan,BLACK);
	whiteCount = GetDolLoc(pan,WHITE);

	//가중치 테이블을 초기화 한다;
	memset(weigthBlackPan,15*15,sizeof(int));
	memset(weigthWhitePan,15*15,sizeof(int));
	//int weigthBlackPan[15][15] = {0};
	//int weigthWhitePan[15][15] = {0};

	if(node == BLACK)
	{
		for(i = 0; i < blackCount ; i++)
		{
			cnt = 0;
			for(j = 0 ; j < 0 ; j++)
			{
				if(blackdols[i].row - j < 0) // 바둑판 범위를 벗어나면.
				{
					break;
				}
				//검은돌의 한점을 기준으로 하여 위쪾에 돌을 구한다.
				doll[j].row = blackdols[i].row - j;
				doll[j].col = blackdols[i].col;
				cnt++;
			}			
		}
		//_MakeWeigth(pan,weigthBlackPan,doll,cnt , (cnt < 5?cnt:5) ,BLACK);
	}
	
	//for(i)


	return 0;
}

//가중치를 계한 한다.
void _MakeWeigth(int pan[][15],int weigthPan[][15],Dol dols[] , int cont , int type,eNode node)
{
	int empte	= 0;
	int dol		= 0;
	int i;

	int cntMyDol = 0;
	int cntOtherDol = 0;
	int cntEmptyDol = 0;

	Dol myDols[4] = {0};
	Dol otherDols[4] = {0};
	Dol empteDols[4] = {0};
	//데이터를 검출 한다.

	eNode otherNode = (node == BLACK)?BLACK:WHITE;

	

	for(i = 0; i < 5 ; i++)
	{
		if(pan[dols[i].row][dols[i].col] == node)
		{
			myDols[i].node = node;
			myDols[i].indxe = i;
			cntMyDol++;
		}
		else if(pan[dols[i].row][dols[i].col] == otherNode)
		{
			otherDols[i].node = node;
			otherDols[i].indxe = i;
			cntOtherDol++;
		}
		else //Empty 이면.
		{
			empteDols[i].node = node;
			empteDols[i].indxe = i;
			cntEmptyDol++;
		}
	}

	if(cntOtherDol > 0) //구간내에 상대방 돌이 있으면 가중치 -1 로 설정 한다.
	{
		for(i = 0; i < cntEmptyDol ; i++ )
		{
			weigthPan[empteDols[i].row][empteDols[i].col] = -1;
		}
	}
	else //다시 가중치 설정.
	{
		int weightCount = 5;
		if(cntEmptyDol == 1)
		{
			weigthPan[empteDols[0].row][empteDols[0].col] = weightCount;
		}
		if(cntEmptyDol == 2)
		{
			int valid = 1;
			for(i = 0 ; i < cntMyDol ; i++ )
			{
				if(myDols[i].indxe  == 4) //내돌의 위치가 마지막 위치 이면 존재 하지 않는다.
				{
					valid = 0;
				}
			}
			if(valid)
			{
				for(i = 0 ; i < cntEmptyDol ; i++ )
				{
					if(weigthPan[empteDols[i].row][empteDols[i].col] < 4) //이미 더 높은 가중치가 설정 되어 있는지.
					{
						weigthPan[empteDols[i].row][empteDols[i].col]  = 4;
					}
				}
			}
		}

		weightCount--;

		//
		

	}
	

	if(type == 5) //5개를 둘수 있는 자리를 검사 한다.
	{
		for(i = 0; i < 5; i++)
		{
			if(pan[dols[i].row][dols[i].col] == node)
			{
				dols[i].node = node;
				dol++;
			}
			else if(pan[dols[i].row][dols[i].col] != WHITE && pan[dols[i].row][dols[i].col] != BLACK)
			{
				dols[i].node = NONE;
				empte++;
			}
		}
		if(dol == 4 && empte == 1) //가능한 케이스.
		{
			for(i = 0; i < 5;i++ )
			{
				if(dols[i].node == NONE)
				{
					weigthPan[dols[i].row][dols[i].col] = 5;
				}
			}
		}
	}
	else if(type == 4) //4개를 둘수 있는 자리를 검사 한다.) //4개를 연속으로 둘수 있는 자리를 구한다.
	{
		for(i = 0; i < 4; i++)
		{
			if(pan[dols[i].row][dols[i].col] == node)
			{
				dols[i].node = node;
				dol++;
			}
			else if(pan[dols[i].row][dols[i].col] != WHITE && pan[dols[i].row][dols[i].col] != BLACK)
			{
				dols[i].node = NONE;
				empte++;
			}
		}

		if(dol == 3 && empte == 1) //가능한 케이스.
		{
			for(i = 0; i < 5;i++ )
			{
				if(dols[i].node == NONE)
				{
					weigthPan[dols[i].row][dols[i].col] = 4;
				}
			}
		}
	}
	else if(type == 3) //4개를 둘수 있는 자리를 검사 한다.) //4개를 연속으로 둘수 있는 자리를 구한다.
	{

	}
	return 0;
}





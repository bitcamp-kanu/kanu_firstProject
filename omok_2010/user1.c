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
	//- ���ϴ� --
	ALLDOL, //��ü ����.
};

typedef enum _eNode  eNode;
struct _dol
{
	int row;
	int col;
	int weigth; //����ġ
	eNode node;
	int indxe; //�迭�� �ε���.
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

//�� �� ��ġ�� ����� ���� �Ѵ�.
int GetDolLoc(int pan[][15], eNode node)
{
	//���� �Ҵ��� �Ⱦ 
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
	static eNode dol = NONE; //ó�� ����� �ѹ��� ����.i
	int blackCnt = 0;
	int whiteCnt = 0;


	if(pan == NULL) //ó�� ����.
	{
		dol = (eNode)(*x);
	}
	dolCnt = GetDolCount(pan,dol);

	
	blackCnt = GetDolCount(pan,BLACK);
	whiteCnt = GetDolCount(pan,WHITE);

	if(dol == BLACK) //���� �̸�
	{
		switch(dolCnt)
		{
		case 0:	 //ù���̸� �߾ӿ� �ִ´�.
			*x = 17;
			*y = 17;
			break;
		case 1:			//��°��
			//������ ���� ���鼭 �ִ´�.


			break;
		case 2:			//��°��. 
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

//����ġ�� ����Ѵ�.
int MakeWeigth(int pan[][15],eNode node)
{
	int blackCount, whiteCount;
	int i ,j , cnt;

	Dol doll[5] = {{-1,-1}};

	blackCount = GetDolLoc(pan,BLACK);
	whiteCount = GetDolLoc(pan,WHITE);

	//����ġ ���̺��� �ʱ�ȭ �Ѵ�;
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
				if(blackdols[i].row - j < 0) // �ٵ��� ������ �����.
				{
					break;
				}
				//�������� ������ �������� �Ͽ� ���U�� ���� ���Ѵ�.
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

//����ġ�� ���� �Ѵ�.
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
	//�����͸� ���� �Ѵ�.

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
		else //Empty �̸�.
		{
			empteDols[i].node = node;
			empteDols[i].indxe = i;
			cntEmptyDol++;
		}
	}

	if(cntOtherDol > 0) //�������� ���� ���� ������ ����ġ -1 �� ���� �Ѵ�.
	{
		for(i = 0; i < cntEmptyDol ; i++ )
		{
			weigthPan[empteDols[i].row][empteDols[i].col] = -1;
		}
	}
	else //�ٽ� ����ġ ����.
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
				if(myDols[i].indxe  == 4) //������ ��ġ�� ������ ��ġ �̸� ���� ���� �ʴ´�.
				{
					valid = 0;
				}
			}
			if(valid)
			{
				for(i = 0 ; i < cntEmptyDol ; i++ )
				{
					if(weigthPan[empteDols[i].row][empteDols[i].col] < 4) //�̹� �� ���� ����ġ�� ���� �Ǿ� �ִ���.
					{
						weigthPan[empteDols[i].row][empteDols[i].col]  = 4;
					}
				}
			}
		}

		weightCount--;

		//
		

	}
	

	if(type == 5) //5���� �Ѽ� �ִ� �ڸ��� �˻� �Ѵ�.
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
		if(dol == 4 && empte == 1) //������ ���̽�.
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
	else if(type == 4) //4���� �Ѽ� �ִ� �ڸ��� �˻� �Ѵ�.) //4���� �������� �Ѽ� �ִ� �ڸ��� ���Ѵ�.
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

		if(dol == 3 && empte == 1) //������ ���̽�.
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
	else if(type == 3) //4���� �Ѽ� �ִ� �ڸ��� �˻� �Ѵ�.) //4���� �������� �Ѽ� �ִ� �ڸ��� ���Ѵ�.
	{

	}
	return 0;
}





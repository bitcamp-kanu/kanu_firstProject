#include "starStack.h"
#include "stdlib.h"


StarNode* _queueStar[_QUESIZE_] = {0};
int _curPos = 0;

#define _MAP_SIZSE_ 30
//#define _TEST_
//새로운 노드를 생성 한다.
#ifdef _TEST_
int _test = 0;
#endif
StarNode* newNode()
{
	StarNode* pNode = (StarNode*)malloc(sizeof(StarNode));
#ifdef _TEST_
	pNode -> x = _test++%_QUESIZE_;
	pNode -> y = 0;
#else
	pNode -> x = rand()%_MAP_SIZSE_ * 2;
	pNode -> y = rand()%_MAP_SIZSE_;
#endif
	return pNode;
}
//Stack의 맨 위에서 개체를 제거하고 반환합니다.
StarNode* Pop()
{
	StarNode* pNode = NULL;
	if(!IsEmptyStack())
	{
		pNode = _queueStar[--_curPos];
		_queueStar[_curPos] = 0x00;
	}
	return pNode;
}
//개체를 Stack의 맨 위에 삽입합니다.
//return 현재 Stack 에 들어가 있는 갯수. 
int Push(StarNode* node)	
{	
	if(!IsFullStack())
	{
		_queueStar[_curPos ] = node;
		_curPos++;
	}
	return _curPos;
}
//시작 부분에서 개체를 제거하지않고 반환 합니다.
StarNode* Peek()
{
	StarNode* pNode = NULL;
	if(!IsEmptyStack())
	{
		pNode = _queueStar[_curPos - 1];
	}
	return pNode;
}
//큐가 비었는지를 검사 한다.
bool IsEmptyStack()
{
	return  (_curPos == 0);
}
//큐가 풀 상태 인지를 검사한다.
bool IsFullStack()
{
	return  (_curPos >=  _QUESIZE_);
}

void OnNode(StarNode* pNdoe)
{
	gotoxy(pNdoe->x,pNdoe->y);
	printf("☆");
}
void OffNode(StarNode* pNdoe)
{
	gotoxy(pNdoe->x,pNdoe->y);
	printf(" ");
}

void main_star()
{
	bool bStackDriect = true;
	while(1)
	{
		if(IsEmptyStack()) // 큐가 비어 
		{
			bStackDriect = true;
		}
		else if(IsFullStack())
		{
			bStackDriect = false;
		}

		if(bStackDriect)
		{
			if(!IsFullStack())
			{
				StarNode* pNode = newNode();
				Push(pNode);
				OnNode(pNode);
			}
		}
		else
		{
			if(!IsEmptyStack())
			{
				StarNode* pNode = Pop();
				OffNode(pNode);
				free(pNode);
				pNode = NULL;

			}
		}
		Sleep(100);
	}
}
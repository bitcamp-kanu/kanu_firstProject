#include "starStack.h"
#include "stdlib.h"


StarNode* _queueStar[_QUESIZE_] = {0};
int _curPos = 0;

#define _MAP_SIZSE_ 30
//#define _TEST_
//���ο� ��带 ���� �Ѵ�.
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
//Stack�� �� ������ ��ü�� �����ϰ� ��ȯ�մϴ�.
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
//��ü�� Stack�� �� ���� �����մϴ�.
//return ���� Stack �� �� �ִ� ����. 
int Push(StarNode* node)	
{	
	if(!IsFullStack())
	{
		_queueStar[_curPos ] = node;
		_curPos++;
	}
	return _curPos;
}
//���� �κп��� ��ü�� ���������ʰ� ��ȯ �մϴ�.
StarNode* Peek()
{
	StarNode* pNode = NULL;
	if(!IsEmptyStack())
	{
		pNode = _queueStar[_curPos - 1];
	}
	return pNode;
}
//ť�� ��������� �˻� �Ѵ�.
bool IsEmptyStack()
{
	return  (_curPos == 0);
}
//ť�� Ǯ ���� ������ �˻��Ѵ�.
bool IsFullStack()
{
	return  (_curPos >=  _QUESIZE_);
}

void OnNode(StarNode* pNdoe)
{
	gotoxy(pNdoe->x,pNdoe->y);
	printf("��");
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
		if(IsEmptyStack()) // ť�� ��� 
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
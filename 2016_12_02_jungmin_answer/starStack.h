#pragma once
#include "turboc.h"
struct _starNode
{
	int x;
	int y;
};
typedef struct _starNode StarNode;
#define _QUESIZE_ 100

extern StarNode* _queueStar[_QUESIZE_];


//���ο� ��带 ���� �Ѵ�.
StarNode* newNode();



//ť���� �Լ� �� ����.
extern int _curPos;			//Stack �� ���� �Է� ��ġ�� ��Ÿ ����. - !���� ���� �Է� ��ġ�� (���� ��ġ �ƴ�)
StarNode* Pop();			//Stack�� �� ������ ��ü�� �����ϰ� ��ȯ�մϴ�.
int Push(StarNode* node);	//��ü�� Stack�� �� ���� �����մϴ�.
StarNode* Peek();			//���� �κп��� ��ü�� ���������ʰ� ��ȯ �մϴ�.
bool IsEmptyStack();		//Stack �� ��������� �˻� �Ѵ�.
bool IsFullStack();			//Stack �� Ǯ ���� ������ �˻��Ѵ�.

void OnNode(StarNode* pNdoe);
void OffNode(StarNode* pNdoe);
void main_star();





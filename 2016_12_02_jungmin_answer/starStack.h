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


//새로운 노드를 생성 한다.
StarNode* newNode();



//큐관련 함수 및 변수.
extern int _curPos;			//Stack 의 다음 입력 위치를 나타 낸다. - !주위 다음 입력 위치임 (현재 위치 아님)
StarNode* Pop();			//Stack의 맨 위에서 개체를 제거하고 반환합니다.
int Push(StarNode* node);	//개체를 Stack의 맨 위에 삽입합니다.
StarNode* Peek();			//시작 부분에서 개체를 제거하지않고 반환 합니다.
bool IsEmptyStack();		//Stack 가 비었는지를 검사 한다.
bool IsFullStack();			//Stack 가 풀 상태 인지를 검사한다.

void OnNode(StarNode* pNdoe);
void OffNode(StarNode* pNdoe);
void main_star();





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _unit{
	char name[12];
	void (*function)(int[][15],int*,int*);
	int color;
	int point;
};
typedef struct _unit	Unit;

void panInit(int[][15]);
void panDisplay(int[][15], const char * );
int setPosition(int[][15], int,int,int);
int judge(int[][15], Unit,int,int);


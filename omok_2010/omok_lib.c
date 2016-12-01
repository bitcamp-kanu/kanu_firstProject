#include "omok.h"

void panInit(int stone[][15])
{
	int i,j;
	int size = 15;

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i==0)
			{
				if(j==0)				//모서리.
				{
					stone[i][j]=2; 
				}
				else if(j==size-1)		//오른쪽 끝.
				{
					stone[i][j]=4; 
				}
				else
				{
					stone[i][j]=3;
				}
			}
			else if(i==size-1)
			{
				if(j==0) stone[i][j]=8;
				else if(j==size-1) stone[i][j]=10;
				else	stone[i][j]=9;
			}
			else
			{
				if(j==0) stone[i][j]=5;
				else if(j==size-1) stone[i][j]=7;
				else	stone[i][j]=6;
			}
		}

	}
}

void panDisplay(int stone[][15], const char *name)
{
	int i,j;
	int size = 15;
	char *marker[]={"○","●","┌","┬","┐","├","┼","┤","└","┴","┘"};

	printf("%s thinking.\n",name);
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			//printf("%s",marker[stone[i][j]]);
			printf("%02d",stone[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%s",marker[stone[i][j]]);
			//printf("%02d",stone[i][j]);
		}
		printf("\n");
	}

}
int setPosition(int field[][15], int stone,int x,int y)
{
	if(y>14 || y<0 || x>14 || x<0 || field[y][x]==0 || field[y][x]==1){
		return 1;
	}
	else		field[y][x] = stone;
	return 0;
}

int judge(int stone[][15], Unit player,int px,int py)
{
	int i,x,y;
	int size = 15;
	int count;

	count=0;
	for(i=0;i<size;i++)
	{
		if(stone[py][i]==player.color)
		{
			count++;
			if(count>4)	return 1;
		}
		else if(count)	count=0;
	}
	count=0;
	for(i=0;i<size;i++)
	{
		if(stone[i][px]==player.color)
		{
			count++;
			if(count>4)	return 1;
		}
		else if(count)	count=0;
	}
	count=0;
	i = py-px;
	for(y=0;y<size;y++)
	{
		x = y-i;
		if( x>=0 && x<size){
			if(stone[y][x]==player.color)
			{
				count++;
				if(count>4)	return 1;
			}
			else if(count)	count=0;
		}
	}
	count=0;
	i = py+px;
	for(y=0;y<size;y++)
	{
		x = i-y;
		if( x>=0 && x<size){
			if(stone[y][x]==player.color)
			{
				count++;
				if(count>4)	return 1;
			}
			else if(count)	count=0;
		}
	}
	count=0;
	return 0;
}


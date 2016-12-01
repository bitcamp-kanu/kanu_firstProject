#include "omok.h"

void user1(int[][15],int*,int*);
void user2(int[][15],int*,int*);
void user3(int[][15],int*,int*);
void user4(int[][15],int*,int*);

int gameon(Unit *black, Unit *white);

int main(int argc, char *argv[])
{
	int black, white;
	int winner;
	int rank[5][5] = {0};
	Unit player[4] = {
		{"Team-1",user1},
		{"Team-2",user2},
		{"Team-3",user3},
		{"Team-4",user4}
	};


	for(black=0;black<4;++black){
		for(white=0;white<4;++white){
			if(black!=white){
				player[black].color = 0;
				player[white].color = 1;

				winner = gameon(player+black,player+white);
				system("pause");
				if(winner == 0 ){
					rank[black][white]++;
				}
				if(winner == 1 ){
					rank[white][black]++;
				}
			}
		}
	}

	{
		int i,k;
		printf("\t");
		for(i=0;i<4;++i){
			printf("%s\t", player[i].name);
		}
		printf("\n");
		for(i=0;i<4;++i){
			printf("%s", player[i].name);
			for(k=0;k<4;++k){
				printf("\t%d", rank[i][k]);
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}

int gameon(Unit *black, Unit *white){
	int stoneCount=0;
	int pan[15][15];
	int dummy[15][15];
	int panSize=15;
	Unit *player;
	int stone=0;//0 is black
	int x=0,y=1;
	int i;
	
	panInit(pan);
	panDisplay(pan, "");

	black->function(pan,&x,&y);
	white->function(pan,&y,&y);
	x = y = EOF;
	while(1){
		memcpy(dummy,pan,sizeof(dummy));
		player = (stone==0)?	black:	white;
		i=0;
		do{
			player->function(pan,&x,&y);
			++i;
			if(i>1){
				printf("%s.%s wrong position.\n", player->name, (player->color==0)?"¡Û":"¡Ü"); 
				if(i>5){
					printf("%s failed to process SORRY \n", player->name);
					return 1-stone;
				}
			}
		}while( setPosition(pan,player->color,x,y) );

		panDisplay(pan, player->name);

		if(judge(pan,*player,x,y)){
			printf("%s %s Win !!!!!!!\n",player->name, (player->color)?"¡Ü":"¡Û");
			break;
		}

		stone ^= 1;

		stoneCount++;
		if(stoneCount>=(panSize*panSize)){
			stone = EOF;
			break;
		}
		system("cls");
	}	
	if( stone == EOF ){
		printf("Full places.\n¹«½ÂºÎ.");
	}

	return stone;
}


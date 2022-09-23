#include <stdio.h>
#include <string.h>
#include <stdbool.h>  			/*true false eval 01*/
#include <stdlib.h>  			/*memory allocation*/
#include "engine.h"

void pieces(pi (*pc)[32])            	//piece initialization
{
	pi pch[32]= {				//black pieces
		{{7,0}, {7,0}, "br1", 0, 5},
		{{7,1}, {7,1}, "bk1", 0, 3},
		{{7,2}, {7,2}, "bb1", 0, 3},
		{{7,3}, {7,3}, "bqn", 0, 9},
		{{7,4}, {7,4}, "bKn", 0, 0},
		{{7,5}, {7,5}, "bb2", 0, 3},
		{{7,6}, {7,6}, "bk2", 0, 3},
		{{7,7}, {7,7}, "br2", 0, 5},
		{{6,0}, {6,0}, "bp1", 0, 1},
		{{6,1}, {6,1}, "bp2", 0, 1},
		{{6,2}, {6,2}, "bp3", 0, 1},
		{{6,3}, {6,3}, "bp4", 0, 1},
		{{6,4}, {6,4}, "bp5", 0, 1},
		{{6,5}, {6,5}, "bp6", 0, 1},
		{{6,6}, {6,6}, "bp7", 0, 1},
		{{6,7}, {6,7}, "bp8", 0, 1},
		{{0,0}, {0,0}, "wr1", 0, 5},    	//white pieces
		{{0,1}, {0,1}, "wk1", 0, 3},
		{{0,2}, {0,2}, "wb1", 0, 3},
		{{0,3}, {0,3}, "wqn", 0, 9},
		{{0,4}, {0,4}, "wKn", 0, 0},
		{{0,5}, {0,5}, "wb2", 0, 3},
		{{0,6}, {0,6}, "wk2", 0, 3},
		{{0,7}, {0,7}, "wr2", 0, 5},
		{{1,0}, {1,0}, "wp1", 0, 1},
		{{1,1}, {1,1}, "wp2", 0, 1},
		{{1,2}, {1,2}, "wp3", 0, 1},
		{{1,3}, {1,3}, "wp4", 0, 1},
		{{1,4}, {1,4}, "wp5", 0, 1},
		{{1,5}, {1,5}, "wp6", 0, 1},
		{{1,6}, {1,6}, "wp7", 0, 1},
		{{1,7}, {1,7}, "wp8", 0, 1}};

	for (int i=0; i<32; i++)
	{
		(*pc)[i] = pch[i];
	}
}

char *(* board())[8] 			//board
{
	static char * b[8][8];
	return b;
}

void play()			//control the game play
{
	pi pc[32];	 
	char *(*c)[8];
	int w = 0;
	int mode = 1; 		//1 is in play, 0 is done
	int k;
	static pos pos_b[70];
	static pos pos_w[70];
	c = board();			//get board from board fn
	pieces(&pc);
	for (int i=0;i<32;i++)
	{
		c[pc[i].cpos[0]][pc[i].cpos[1]] = pc[i].id;   //c = move(&bk1, c);
	}
	engine(pc, c, w, pos_w, pos_b);
	while (mode == 1)
	{
		if (w==1){
			printf("player 2 turn\n");
			w = 0;
			engine(pc, c, w, pos_w, pos_b);
			printf("2222222\n");
			mode = scoring(pc, c, w, pos_b, pos_w, mode);
		}
		else if (w==0){
			w = 1;
			engine(pc, c, w, pos_w, pos_b);
			mode = scoring(pc, c, w, pos_w, pos_b, mode);
		}
		//mode = 0;
		display(c);
	}
}

void main()				
{
	play();
}

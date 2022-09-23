#include "engine.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>                    /*true false eval 01*/
#include <stdlib.h>                     /*memory allocation*/
#include <time.h>

int knight(int x, int y, int j, pos *pos, char *id)
{
	int a, b;
	a = x+2;
	b = y+1;
	if (0<=a && 7>=a && 0<=b && 7>=b)
	{
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
	}
	a = x+1;
	b = y+2;
	if (0<=a && 7>=a && 0<=b && 7>=b)
	{
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
	}
	a = x+1;
	b = y-2;
	if (0<=a && 7>=a && 0<=b && 7>=b)
	{
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
	}
	a = x+2;
	b = y-1;
	if (0<=a && 7>=a && 0<=b && 7>=b)
	{
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
	}
	a = x-2;
	b = y+1;
	if (0<=a && 7>=a && 0<=b && 7>=b)
	{
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
	}
	a = x-1;
	b = y+2;
	if (0<=a && 7>=a && 0<=b && 7>=b)
	{
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
                j += 1;
        }
        a = x-1;
        b = y-2;
        if (0<=a && 7>=a && 0<=b && 7>=b)
        {
                pos[j].p[0] = a;
                pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
                j += 1;
        }
        a = x-2;
        b = y-1;
        if (0<=a && 7>=a && 0<=b && 7>=b)
        {
                pos[j].p[0] = a;
                pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
                j += 1;
        }
	return j;
}

int rook(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z)
{
	/* Its going to be 4 if statements - two for row and two for column
	   Take the row number - loop increment (while i<8) and keep incrementing the row 
	   keeping the column constant and (check if own piece or opp. is blocking: yes - and and break)
	   or add  
	   valid move list and keep incrementing to next pos. 
	   Then do the same for row but decrements and then the same for column increments and 
	   decrements
	   When a piece is blocking then include that move and then break) */

	int a, b;
	a = x;
	while (a<7)
	{
		a = a+1;
		b = y;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	while (a>0)
	{
		a = a-1;
		b = y;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	b = y;
	while (b<7)
	{
		a = x;
		b = b+1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	b = y;
	while (b>0)
	{
		a = x;
		b = b-1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	return j;
}

int bishop(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z)
{
	//4 conditions: 1- row inc, col inc, 2- row inc col dec, 3- row dec col inc, 4- row dec col dec
 	//for each - there is conditional statement and stop if piece is included
	
	int a, b;
	a = x;
	b = y;
	while (a<7 && b<7)
	{
		a = a+1;
		b = b+1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a<7 && b>0)
	{
		a = a+1;
		b = b-1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a>0 && b<7)
	{
		a = a-1;
		b = b+1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a>0 && b>0)
	{
		a = a-1;
		b = b-1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	return j;
}

int queen(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z)
{
	//8 conditions: rook and bishop rules included
	
	int a, b;
	a = x;
	while (a<7)
	{
		a = a+1;
		b = y;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	while (a>0)
	{
		a = a-1;
		b = y;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	b = y;
	while (b<7)
	{
		a = x;
		b = b+1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	b = y;
	while (b>0)
	{
		a = x;
		b = b-1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a<7 && b<7)
	{
		a = a+1;
		b = b+1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a<7 && b>0)
	{
		a = a+1;
		b = b-1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a>0 && b<7)
	{
		a = a-1;
		b = b+1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	a = x;
	b = y;
	while (a>0 && b>0)
	{
		a = a-1;
		b = b-1;
		pos[j].p[0] = a;
		pos[j].p[1] = b;
		strcpy(pos[j].pid, id); 
		j += 1;
		if (c[z-a][b] != NULL)
		{
			break;
		}
	}
	return j;
}

int pawn(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z)
{
	if (x<7 && c[z-(x+1)][y] == NULL)
	{
		pos[j].p[0] = x+1;   // one step
		pos[j].p[1] = y;
		if (x+1==7)
			strcpy(pos[j].pid, "pp");   //pawn promotion
		else 
			strcpy(pos[j].pid, id);
		j += 1;
		if (x=1 && c[z-(x+2)][y] == NULL)   //two step
		{
			pos[j].p[0] = x+2;
			pos[j].p[1] = y;
			strcpy(pos[j].pid, id);
			j += 1;
		}
	}
	if (x<7 && y>0 && c[z-(x+1)][y-1]!=NULL)  //side attack left
	{
		if (strncmp(c[z-(x+1)][y-1], "b", 1)==0) //strncmp with null not valid
		{
			pos[j].p[0] = x+1;
			pos[j].p[1] = y-1;
			if (x+1==7)
			{
				strcpy(pos[j].pid, "pp");   //pawn promotion
			}
			else
				strcpy(pos[j].pid, id);
			j += 1;
		}
	}
	if (x<7 && y<7 && c[z-(x+1)][y+1]!=NULL) // side attack right
	{
		if (strncmp(c[z-(x+1)][y+1], "b", 1)==0)
		{
			pos[j].p[0] = x+1;
			pos[j].p[1] = y+1;
			if (x+1==7)
			{
				strcpy(pos[j].pid, "pp");   //pawn promotion
			}
			else 
				strcpy(pos[j].pid, id);
			j += 1;
		}
	}
	return j;
}

int king(int x, int y, int j, pos *pos, char *id)
{
	if (x<7)
	{
		pos[j].p[0] = x+1;
		pos[j].p[1] = y;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (x>0)
	{
		pos[j].p[0] = x-1;
		pos[j].p[1] = y;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (y<7)
	{
		pos[j].p[0] = x;
		pos[j].p[1] = y+1;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (y>0)
	{
		pos[j].p[0] = x;
		pos[j].p[1] = y-1;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (x<7 && y>0)
	{
		pos[j].p[0] = x+1;
		pos[j].p[1] = y-1;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (x<7 && y<7)
	{
		pos[j].p[0] = x+1;
		pos[j].p[1] = y+1;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (x>0 && y>0)
	{
		pos[j].p[0] = x-1;
		pos[j].p[1] = y-1;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	if (x>0 && y<7)
	{
		pos[j].p[0] = x-1;
		pos[j].p[1] = y+1;
		strcpy(pos[j].pid, id);
		j += 1;
	}
	return j;
}


/*
   Scoring Function
   Input - pos w, pos b, turn, pc
   Output - move pos and id updated for pc
*/

void get_score(pos *pos_w, int *max, int *k, char *(*c)[8], int w)
{
	*max = -1;
	char wh[2];
	char bl[2];
	if (w == 0){
		strcpy(wh, "b");
		strcpy(bl, "w");
	}
	else{
		strcpy(wh, "w");
		strcpy(bl, "b");
	}
	while (strncmp(pos_w[*k].pid, wh, 1) == 0)    //pos_w here is b or w based on turn 
	{					      //the above check - to do till end of struct
		int x = pos_w[*k].p[0];
		int y = pos_w[*k].p[1];
		if (c[x][y] == NULL)
		{
			pos_w[*k].s = 0;
		}
		else if (strncmp(c[x][y], wh, 1) == 0)
			pos_w[*k].s = -1;
		else if (strncmp(c[x][y], bl, 1) == 0)
		{
			if (strncmp((c[x][y]+1), "k", 1)==0 || strncmp((c[x][y]+1), "b", 1)==0)
				pos_w[*k].s = 3;
			else if (strncmp((c[x][y]+1), "r", 1)==0)
				pos_w[*k].s = 5;
			else if (strncmp((c[x][y]+1), "q", 1)==0)
				pos_w[*k].s = 9;
			else if (strncmp((c[x][y]+1), "K", 1)==0)
				pos_w[*k].s = 10;
			else if (strncmp((c[x][y]+1), "p", 1)==0)
				pos_w[*k].s = 1;
		}
		if (pos_w[*k].s > *max)    // max score move
			*max = pos_w[*k].s;
		*k += 1;
	}
}

void get_moves(char id[3], int p[2], pos *pos_next, char *(*c)[8], int *max_s1, int w)
{
	int x;
	int z;
	if (w == 1)
	{
		x = p[0];
		z = 2*x;
	}
	else 
	{
		x = 7 - p[0];
		z = 7;
	}
	int y = p[1];
	int j = 0;
	if (strncmp((id+1), "k", 1) == 0)
	{
		j = knight(x, y, j, pos_next, id);
	}
	else if (strncmp((id+1), "r", 1) == 0)
	{
		j = rook(x, y, j, pos_next, id, c, z);
	}
	else if (strncmp((id+1), "b", 1) == 0)
	{
		j = bishop(x, y, j, pos_next, id, c, z);
	}
	else if (strncmp((id+1), "q", 1) == 0)
	{
		j = queen(x, y, j, pos_next, id, c, z);
	}
	else if (strncmp((id+1), "p", 1) == 0)
	{
		j = pawn(x, y, j, pos_next, id, c, z);
	}
	else if (strncmp((id+1), "K", 1) == 0)
	{
		j = king(x, y, j, pos_next, id);
	}
	int k = 0;
	get_score(pos_next, max_s1, &k, c, w);
	for (int k=0;k<j;k++)
	{
        	if (w == 0)
		{
			pos_next[k].p[0] = 7 - pos_next[k].p[0];
		}
		//printf("next_table: %d,%s,%d,%d,%d\n", k, pos_next[k].pid, pos_next[k].p[0], 
				//pos_next[k].p[1], pos_next[k].s);
	}
}
	
int scoring(pi *pc, char *(*c)[8], int w, pos *pos_w, pos *pos_b, int mode)
{
	static pos pos_next[15];
	int max = -1;				//-1 because that is the lowest score
	int max_s1 = -1;
	int k = 0;
	int max_i[30];				//max score for next mov seq
	int n;
	int j = 0;
	{
		get_score(pos_w, &max, &k, c, w);	//score calculator 
		for (int i=0;i<k;i++)		//multi-step look ahead 
		{
			if (pos_w[i].s == max)
			{
				get_moves(pos_w[i].pid, pos_w[i].p, pos_next, c, &max_s1, w); //getmove&score
				pos_w[i].s1 = max_s1;
			}
			else
				pos_w[i].s1 = -2;
		}
		for (int i=0;i<k;i++)			//find max score for second step
		{
			if (pos_w[i].s1 > max_s1)    
			{
				max_s1 = pos_w[i].s1;
			}
		}
		for (int i=0;i<k;i++)			//get indexes of items with max score
		{
			if (pos_w[i].s1 == max_s1)
			{
				max_i[j] = i;
				j += 1;
			}
		}
		if (j>=1)				//pick random from max score items
		{
			srand(time(0));
			n = rand() % j;
			printf("max_id_piece %d, %s\n", max_i[n], pos_w[max_i[n]].pid);
			for (int i=0; i<32; i++)
			{
				if (strncmp(pc[i].id, pos_w[max_i[n]].pid, 3)==0)
				{
					//printf("tet %s, %s:", pc[i].id, pos_w[max_i[n]].pid);
					c[pc[i].cpos[0]][pc[i].cpos[1]] = NULL;
					pc[i].cpos[0] = pos_w[max_i[n]].p[0];
					pc[i].cpos[1] = pos_w[max_i[n]].p[1];
					c[pc[i].cpos[0]][pc[i].cpos[1]] = pc[i].id;
				}
			}
		}
		printf("max_score and id: %d, %d\n", max_s1, max_i[n]);
		/*printf("k, score: %d, %d\n", k-1, max); 
		printf("pos_score_white\n");
		for (int i=0;i<k;i++)
		{
        		printf("%d %s,%d,%d,%d,%d\n", i, pos_w[i].pid, pos_w[i].p[0], pos_w[i].p[1],
					pos_w[i].s, pos_w[i].s1);
		}*/
	}
	if (max_s1 == 2){
		mode = 0;
		printf("Congratulations! Game Over. The Register is now closed");
	}
	else 
		mode = 1;
	return mode;
}

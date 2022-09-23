#include "engine.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>                    /*true false eval 01*/
#include <stdlib.h>                     /*memory allocation*/


char *(* move(pi * a, char *(*c)[8]))[8]        //call move to move a piece 
{
        int x, y;
        x = a->cpos[0];
        y = a->cpos[1];
        c[0][1] = a->id;
        return c;
}



void display(char * (*d)[8])            //Display Board
{
        for (int i=0; i<8; ++i)
        {
                printf("\n %d", i);
                for (int j=0; j<8; ++j)
                {
                        if (d[i][j] == NULL)
                                printf(" _ _ ");
                        else
                                printf(" %s ", d[i][j]);
                }
        }       printf("\n    0    1    2    3    4    5    6    7\n");
}


void engine(pi *pc, char *(*c)[8], int w, pos *pos_w, pos *pos_b)
{
	int x, y;
	int j=0;
	int z;
	if (w == 1)
	{
		for (int i=16; i<32; i++)
		{
			x = pc[i].cpos[0];
			y = pc[i].cpos[1];
			z = 2*x;				//z for board inversion
			if (strncmp(pc[i].id, "wk", 2) == 0)
			{
				j = knight(x, y, j, pos_w, pc[i].id);	
			}
			else if (strncmp(pc[i].id, "wr", 2) == 0)
			{
				j = rook(x, y, j, pos_w, pc[i].id, c, z);	
			}
			else if (strncmp(pc[i].id, "wb", 2) == 0)
			{
				j = bishop(x, y, j, pos_w, pc[i].id, c, z);	
			}
			else if (strncmp(pc[i].id, "wq", 2) == 0)
			{
				j = queen(x, y, j, pos_w, pc[i].id, c, z);	
			}
			else if (strncmp(pc[i].id, "wp", 2) == 0)
			{
				j = pawn(x, y, j, pos_w, pc[i].id, c, z);	
			}
			else if (strncmp(pc[i].id, "wK", 2) == 0)
			{
				j = king(x, y, j, pos_w, pc[i].id);
			}
			else
				printf("%s\n", pc[i].id);
		}
	printf("pos_table_white\n");
	for (int k=0;k<j;k++)
	{
		//printf("%d %s,%d,%d\n", k, pos_w[k].pid, pos_w[k].p[0], pos_w[k].p[1]);
	}
	}
	else if (w == 0)
	{
		j = 0;
		int z = 7;				//z here is outside the loop
		for (int i=0; i<16; i++)
		{
			//printf("111111%d\n\n", j);
			x = 7 - pc[i].cpos[0];		//sub 7 since black moves down
			y = pc[i].cpos[1];
			if (strncmp(pc[i].id, "bk", 2) == 0)
			{
				j = knight(x, y, j, pos_b, pc[i].id);
			}
			else if (strncmp(pc[i].id, "br", 2) == 0)
			{
				j = rook(x, y, j, pos_b, pc[i].id, c, z);
			}
			else if (strncmp(pc[i].id, "bb", 2) == 0)
			{
				j = bishop(x, y, j, pos_b, pc[i].id, c, z);
			}
			else if (strncmp(pc[i].id, "bq", 2) == 0)
			{
				j = queen(x, y, j, pos_b, pc[i].id, c, z);
			}
			else if (strncmp(pc[i].id, "bp", 2) == 0)
			{
				j = pawn(x, y, j, pos_b, pc[i].id, c, z);
			}
			else if (strncmp(pc[i].id, "bK", 2) == 0)
			{
				j = king(x, y, j, pos_b, pc[i].id);
			}
			else
				printf("%s\n", pc[i].id);
		}
	printf("pos_table_black\n");
	for (int k=0;k<j;k++)
	{
		pos_b[k].p[0] = 7-pos_b[k].p[0];	//adjust for sub 7 above
		printf("%d %s,%d,%d\n", k, pos_b[k].pid, pos_b[k].p[0], pos_b[k].p[1]);
	}
	}
}

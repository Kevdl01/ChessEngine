//make next move based on piece argument
#ifndef HEADER_FILE
#define HEADER_FILE


typedef struct pi                 /*global struct for piece */
{
        int ipos[2];            /*initialpos */
        int cpos[2];            /*currentpos */
        char id[3];             /*black or white knight bk or wk*/
        int out;                /*0 or 1 - in game or out*/
        int val;                /*piece value*/
}pi;

typedef struct pos
{
        char pid[3];
        int p[2];
	int s;
	int s1;

}pos;

int knight(int x, int y, int j, pos *pos, char *id);

int rook(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z);

int bishop(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z);

int queen(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z);

int pawn(int x, int y, int j, pos *pos, char *id, char *(*c)[8], int z);

int king(int x, int y, int j, pos *pos, char *id);

char *(* move(pi * a, char *(*c)[8]))[8];        //call move to move a piece 

void display(char * (*d)[8]);

void engine(pi *pc, char *(*c)[8], int w, pos *pos_w, pos *pos_b);

void get_score(pos *pos_w, int *max, int *k, char *(*c)[8], int w);

int scoring(pi *pc, char *(*c)[8], int w, pos *pos_w, pos *pos_b, int mode);

void get_moves(char id[3], int p[2], pos *pos_next, char *(*c)[8], int *max_s1, int w);

#endif

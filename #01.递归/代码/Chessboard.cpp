#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>    // Include for memset

int nCount = 0;
int Matrix[100][100];

//tr,tc(top_row,top_col)：代表棋盘左上角坐标
//sr,sc(special_row, special_col)：代表特殊点坐标
//size:棋盘的大小
void chessBoard(int tr, int tc, int sr, int sc, int size)
{
    if (size == 1) return;

    int s, t;
    s = size/2; // The number of grid the matrix's edge
    t = ++ nCount;

    // locate the special grid on bottom right corner
    if (sr < tr + s && sc < tc +s)
    {
        chessBoard(tr,tc,sr,sc,s);
    }
    else
    {
        Matrix[tr+s-1][tc+s-1] = t;
        chessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    // locate the special grid on bottom left corner
    if (sr < tr + s && sc >= tc + s )
    {
        chessBoard(tr,tc+s,sr,sc,s);
    }
    else
    {
        Matrix[tr+s-1][tc+s] = t;
        chessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }

    // locate the special grid on top right corner
    if (sr >= tr + s && sc < tc + s)
    {
        chessBoard(tr+s,tc,sr,sc,s);
    }
    else
    {
        Matrix[tr+s][tc+s-1] = t;
        chessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    // locate the special grid on top left corner
    if (sr >= tr + s && sc >= tc + s)
    {
        chessBoard(tr+s,tc+s,sr,sc,s);
    }
    else
    {
        Matrix[tr+s][tc+s] = t;
        chessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main()
{
    int t,size,r,c,row,col;
    std::memset(Matrix,0,sizeof(Matrix));    // Use std:: prefix for memset
    scanf("%d",&t);
    scanf("%d%d",&row,&col);

    size = pow(2, t);
    chessBoard(0,0,row,col,size);

    for (r = 0; r < size; r++)
    {
        for (c = 0; c < size; c++)
        {
            printf("%4d ",Matrix[r][c]);
        }
        printf("\n\n");
    }

    return 0;
}
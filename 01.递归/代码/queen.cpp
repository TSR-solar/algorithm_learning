#include <stdio.h>
#include <stdlib.h>
#define N 20
int q[N] = {0};     // 存放各皇后的列号 q[0]不使用
int cnt = 0;        // 总解个数

void output(int n)
{
    cnt++;
    printf("solution %d: \n", cnt);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j == q[i]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}

int place(int i, int j)
{
    if(i == 1) return 1;

    for(int k = 1; k < i; k++)
    {
        if(q[k] == j || (abs(q[k]-j) == abs(i-k)) ) return 0;
    }
    return 1;
}

void queen(int i, int n)
{
    if(i > n) output(n);
    else
    {
        for(int j = 1; j <= n; j++)
        {
            if(place(i,j))
            {
                q[i] = j;
                queen(i+1, n);
            }
        }
    }
}

int main()
{    
    int n;
    scanf("%d", &n);
    queen(1, n);
    return 0;
}
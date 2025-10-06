#include <stdio.h>
#include <vector>
#define N 2000
int n = 0;
int W = 0;

int w[N] = {0};
int v[N] = {0};

int V = 0;      // 最大价值 
int x[N] = {0}; // 最优解


void input()
{
    scanf("%d%d", &n, &W);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void output()
{
    printf("%d\n", V);
    for(int i = 0; i < n; i++)
    {
        if(x[i] == 1) printf("%d ", i+1);
    }
    printf("\n");
}

int bound(int i, int tv)
{
    int max = tv;
    for(int j = i+1; j < n; j++)
    {
        max += w[j];
    }
    return max > V;
}

void dfs(int i, int tw, int tv, int *t)
{
    // 结束递归条件
    if(i > n)
    {
        V = tv;
        for(int j = 0; j < n; j++)
        {
            x[j] = t[j];
        }
        return;
    }

    // 是否向左深入
    if(tw + w[i] <= W)
    {
        t[i] = 1;
        dfs(i+1, tw+w[i], tv+v[i], t);
    } 

    // 是否向右深入
    if(bound(i, tv))
    {
        dfs(i, tw, tv+v[i], t);
    }
}

int main()
{
    input();
    int t[N] = {0};
    dfs(1, 0, 0, t);
    output();
}
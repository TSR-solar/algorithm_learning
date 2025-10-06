#include <stdio.h>
#define N 2000
int c[N][N] = {0};
int s[N] = {0};

int min = 0x3f3f3f3f;
int ans[N] = {0};

int n = 0;

void init()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        s[i] = i;
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
}

void swap(int i, int j)
{
    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

int bound(int i)
{
    int sum = 0;
    for(int j = 0; j < i; j++)
    {
        sum += c[j][s[j]];
    }
    return sum < min;
}

void dfs(int i)
{
    if(i >= n)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += c[j][s[j]];    
        }
        if(sum < min)
        {
            min = sum;
            for(int k = 0; k < n; k++)
            {
                ans[k] = s[k];
            }
        }
    }
    else if(bound(i))
    {
        for(int j = i; j < n; j++)
        {
            swap(i, j);
            dfs(i+1);
            swap(i, j);
        }
    }
}

void output()
{
    printf("%d\n", min);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]+1);
    }
}

int main()
{
    init();
    dfs(0);
    output();
    return 0;
}
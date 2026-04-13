#include <stdio.h>
#include <queue>
using namespace std;
#define N 2000
int n = 0;
int W = 0;

int w[N] = {0};
int v[N] = {0};

int V = 0;      // 最大价值 
int x[N] = {0}; // 最优解

class node
{
public:
    int i = 0; 
    int tw = 0; 
    int tv = 0;
    int t[N] = {0};
    double max = 0;

    void bound()
    {
        int maxw = tw, j = i+1;
        double maxv = tv;
        while(j < n && maxw + w[j] <= W)
        {
            maxv += v[j];
            maxw += w[j];
            j++;
        }

        if(j < n) maxv += v[j] * (W - maxw) / w[j];
        max = maxv;
    }

    node(int ii, int ttw, int ttv, int tt[N], int c)
    {
        i = ii;
        tw = ttw;
        tv = ttv;
        for(int j = 0; j < i-1; j++)
        {
            t[j] = tt[j];
        }
        if(i != 0) t[i-1] = c;
        bound();
    }
};

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

void bfs()
{
    queue<node> q;
    node e0(0, 0, 0, {0}, 0);
    q.push(e0);

    while(!q.empty())
    {
        node e = q.front(); q.pop();
        if(e.i >= n) continue;

        if(e.tw + w[e.i] <= W)
        {
            node e1(e.i+1, e.tw+w[e.i], e.tv+v[e.i], e.t, 1);
            q.push(e1);

            if(e1.tv > V)
            {
                V = e1.tv;
                for(int j = 0; j < n; j++)
                {
                    x[j] = e1.t[j];
                }
            }
        }
        
        if(e.max >= V)
        {
            node e1(e.i+1, e.tw, e.tv, e.t, 0);
            q.push(e1);
        }
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

int main()
{
    input();
    bfs();
    output();
    return 0;
}
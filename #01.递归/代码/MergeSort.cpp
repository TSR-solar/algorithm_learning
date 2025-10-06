#include <stdio.h>
#define N 10000
int a[N] = {0};

void sort(int b, int e)
{
    int f = (b+e)/2;
    if(b == e) return;

    sort(b, f);
    sort(f+1, e);

    int i = b, j = f+1, x = a[i], y = a[j], t = 0;
    int tmp[N] = {0};

    while(i <= f && j <= e)
    {
        if(x <= y)
        {
            tmp[t] = x;
            t++; i++;
            x = a[i];
        }
        else
        {
            tmp[t] = y;
            t++; j++;
            y = a[j];
        }
    }
    while(i <= f)
    {
        tmp[t] = a[i];
        i++; t++;
    }

    while(j <= e)
    {
        tmp[t] = a[j];
        j++; t++;
    }

    for(int i = 0; i < t; i++)
    {
        a[b+i] = tmp[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(0, n-1);
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
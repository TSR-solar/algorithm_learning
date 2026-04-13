#include <stdio.h>
#define N 10000
int a[N] = {0};

void swap(int &a, int &b)
{
    int tmp = a;
    a = b; 
    b = tmp;
}

void sort(int b, int e)
{
    int i = b, j = e, f = a[(b+e)/2];

    if(b >= e) return;

    while(i <= j)
    {
        while(a[i] < f) i++;
        while(a[j] > f) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    sort(b, j); sort(i, e);
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

/*
5
3 5 3 3 6
*/ 
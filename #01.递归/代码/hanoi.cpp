#include <stdio.h>
int t = 0;

// 进行一次移动
void move(int n, int a, int b)
{
    t++;
    printf("move %d from %d to %d\n", n, a, b);
}

// 解决汉诺塔问题
void hanoi(int n, int x, int y, int z)
{
    if(n == 1) move(1, x, z);
    else
    {
        hanoi(n-1, x, z, y);
        move(n, x, z);
        hanoi(n-1, y, x, z);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    printf("Total: %d", t);
    return 0;
}

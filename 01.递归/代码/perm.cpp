#include <iostream>
using namespace std;
#define N 200

void swap(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

// 产生list[k:m]的所有全排列
void perm(int list[], int k, int m)
{
    // 只剩下一个元素
    if(k == m)
    {
        for(int i = 0; i <= m; i++)
        {
            cout << list[i] << ' ';
        }
        cout << endl;
    }
    
    for(int i = k; i <= m; i++)
    {
        swap(list[k], list[i]);
        perm(list, k+1, m);
        swap(list[k], list[i]);
    }
}

int main()
{
    int n = 0;
    int list[N] = {0};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    perm(list, 0, n-1);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int maxinclen(vector<int>& a, int n)
{
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i]) dp[i] = max(dp[j]+1, dp[i]);
        }
    }

    int maxnum = 0;
    for(int i = 0; i < n; i++)
    {
        maxnum = max(maxnum, dp[i]);
    }
    return maxnum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << maxinclen(a, n);
    return 0;
}
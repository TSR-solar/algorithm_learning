#include <iostream>
#include <vector>
#define N 100
using namespace std;

int maxsum(vector<int>& a, int n)
{
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(i == 0) dp[i] = a[i];
        else dp[i] = max(dp[i-1] + a[i], a[i]);
    }

    int max_sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, dp[i]); 
    }
    return max_sum;
}

int main()
{
    int n;
    vector<int> a(N, 0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxsum(a, n);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int triangle(vector<vector<int>>& a, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == n-1) dp[i][j] = a[i][j];
            else dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
        }
    }
    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << triangle(a, n) << endl;
}
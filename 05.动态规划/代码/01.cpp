#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n, W;
    cin >> n >> W;
    vector<int> v(n, 0), w(n, 0);
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for(int i = 0; i <= n; i++)
    {
        for(int r = 0; r <= W; r++)
        {
            if(i == 0 || r == 0) dp[i][r] = 0;
            else if(r < w[i-1]) dp[i][r] = dp[i-1][r];
            else dp[i][r] = max(dp[i-1][r], v[i-1] + dp[i-1][r-w[i-1]]);
        }
    }
    cout << dp[n][W] << endl;
    int i = n, r = W;
    vector<int> res;
    while(i != 0 && r != 0)
    {
        if(dp[i][r] == dp[i-1][r]) i--;
        else
        {
            i--; r -= w[i];
            res.push_back(i);
        }
    }
    reverse(res.begin(), res.end());
    for(int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
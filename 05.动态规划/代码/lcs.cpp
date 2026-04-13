#include <iostream>
#include <vector>
#include <string>
using namespace std;

void lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[m][n] << endl;

    int i = m, j = n;
    string res;
    while(i != 0 && j != 0)
    {
        if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else
        {
            res.push_back(s1[i-1]); i--; j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lcs(s1, s2);
    return 0;
}
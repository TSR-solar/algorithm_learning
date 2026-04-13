#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(1<<(n-1), vector<int>(n, 0));
    for(int v = 0; v < 1<<(n-1); v++)
    {
        for(int i = 0; i < n; i++)
        {
            if(v == 0) dp[v][i] = dist[0][i];
            else
            {
                int min_dist = 1e9;
                for(int j = 0; j < n; j++)
                {
                    int min_dist = 1e9;
                    if(v & (1<<(j-1)))
                    {
                        min_dist = min(min_dist, dp[v^(1<<(j-1))][j] + dist[j][i]);
                    }
                }
                dp[v][i] = min_dist;
            }
        }
    }
    cout << dp[(1<<(n-1))-1][0] << endl;
    return 0;
}
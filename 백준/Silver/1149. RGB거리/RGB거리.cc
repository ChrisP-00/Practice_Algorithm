#include <iostream>

using namespace std; 

int costs[1001][4];
int dp[1001][4];

int main()
{
    int n;
    cin >> n;
    
    for(int idx = 0; idx < n; ++idx)
    {
        for(int color = 0; color < 3; ++color)
        {
            cin >> costs[idx][color];
        }
    }
    
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    
    
    for(int idx = 1; idx < n; ++idx)
    {
        dp[idx][0] = costs[idx][0] + min(dp[idx - 1][1], dp[idx - 1][2]);
        dp[idx][1] = costs[idx][1] + min(dp[idx - 1][0], dp[idx - 1][2]);
        dp[idx][2] = costs[idx][2] + min(dp[idx - 1][0], dp[idx - 1][1]);
    }
    
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    
    return 0;
}
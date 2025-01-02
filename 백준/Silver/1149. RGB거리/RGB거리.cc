#include <iostream>

using namespace std; 

int main()
{
    int n;
    cin >> n;
    
    int dp[1001][4];
    
    for(int idx = 0; idx < n; ++idx)
    {
        for(int color = 0; color < 3; ++color)
        {
            cin >> dp[idx][color];
        }
    }
        
    for(int idx = 1; idx < n; ++idx)
    {
        dp[idx][0] += min(dp[idx - 1][1], dp[idx - 1][2]);
        dp[idx][1] += min(dp[idx - 1][0], dp[idx - 1][2]);
        dp[idx][2] += min(dp[idx - 1][0], dp[idx - 1][1]);
    }
    
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    
    return 0;
}
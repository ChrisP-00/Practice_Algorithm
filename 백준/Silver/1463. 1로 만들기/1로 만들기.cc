#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp (n + 1, 0);

    dp[2] = 1;
    dp[3] = 1;

    for(int idx = 4; idx <= n; ++idx)
    {
        dp[idx] = dp[idx - 1] + 1; 

        if(idx % 3 == 0)
        {
            dp[idx] = min(dp[idx], dp[idx / 3] + 1);
        }

        if(idx % 2 == 0)
        {
            dp[idx] = min(dp[idx], dp[idx / 2] + 1);
        }
    }
 
    cout << dp[n];
    
    return 0;
}
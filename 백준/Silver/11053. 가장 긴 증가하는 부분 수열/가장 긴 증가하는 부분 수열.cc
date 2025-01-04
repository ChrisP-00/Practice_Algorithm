#include <iostream>

using namespace std;

int max (int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int* nums = new int[n];
    int* dp = new int[n];

    for(int idx = 0; idx < n; ++idx)
    {
        cin >> nums[idx];
        dp[idx] = 1;
    }

    int ans = 1;

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(nums[j] < nums[i] & dp[j] >= dp[i])
            {
                dp[i] = dp[j] + 1;
                ans = max(dp[i], ans);
            }
        }
    }
    
    cout << ans;

    delete[] nums;
    delete[] dp;

    return 0;
}
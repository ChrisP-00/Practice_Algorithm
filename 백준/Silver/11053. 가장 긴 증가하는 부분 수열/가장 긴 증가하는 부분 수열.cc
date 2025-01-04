#include <iostream>
#include <algorithm>

using namespace std;

int nums[1001];
int dp[1001] = {1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int idx = 0; idx < n; ++idx)
    {
        cin >> nums[idx];
    }

    fill(dp, dp + n, 1);

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << *max_element(dp, dp + n);

    return 0;
}
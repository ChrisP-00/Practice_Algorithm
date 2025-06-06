#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;

    int dp [12] = {0};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i < 12; ++i)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1]; 
    }

    while(t--)
    {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
    return 0;
}

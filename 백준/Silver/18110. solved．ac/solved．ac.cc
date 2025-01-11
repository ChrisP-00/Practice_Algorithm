#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums (n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    int except = (n * 15 + 50) / 100;
    int count = n - 2 * except;
    if(count <= 0)
    {
        cout << 0;
    }
    else
    {
        for(int idx = except; idx < n - except; ++idx)
        {
            ans += nums[idx];
        }

        cout << (ans + count / 2) / count;
    }

    return 0;
}
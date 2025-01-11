#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    vector<int> nums (n);

    for(int idx = 0; idx < n; ++idx)
    {
        cin >> nums[idx];
    }

    sort(nums.begin(), nums.end());

    for(const int num : nums)
    {
        cout << num << '\n';
    }

    return 0;
}
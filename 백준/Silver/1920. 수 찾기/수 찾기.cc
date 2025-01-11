#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    fast;
    int nums[100001];
    int n;
    cin >> n;

    for(int idx = 0; idx < n; ++idx)
    {
        cin >> nums[idx];
    }

    sort(nums, nums + n);

    int m, num;
    cin >> m;
    while(m--)
    {
        cin >> num;
        if(upper_bound(nums, nums + n, num) - lower_bound(nums, nums + n, num) == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }

    return 0;
}
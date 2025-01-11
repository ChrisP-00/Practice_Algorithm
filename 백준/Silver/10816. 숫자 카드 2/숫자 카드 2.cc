#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    int nums[500002];
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }   

    sort(nums, nums + n);

    int m, num;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> num;
        cout << upper_bound(nums, nums + n, num) - lower_bound(nums, nums + n, num) << ' ';
    }

    return 0;
}
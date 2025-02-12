#include <iostream> 
#include <vector> 

using namespace std; 

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> nums (n + 1, 0);

    for(int i = 1; i <= n; ++i)
    {
        cin >> nums[i];

        nums[i] += nums[i - 1];
    }

    while(m--)
    {
        int i, j;
        cin >> i >> j;

        cout << nums[j] - nums[i - 1] << '\n';
    }

    return 0;
}
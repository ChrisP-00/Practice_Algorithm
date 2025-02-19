#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> oper(n);
    for(int i = n - 1; i >= 0; --i)
    {
        cin >> oper[i];
    }

    deque<int> nums;

    for(int i = 0; i < n; ++i)
    {
        if(oper[i] == 1)
        {
            nums.push_back(i + 1);
        }
        else if(oper[i] == 2)
        {
            nums.insert(nums.end() - 1, i + 1);
        }
        else if(oper[i] == 3)
        {
            nums.push_front(i + 1);
        }
    }

    for(int i = n - 1; i >= 0; --i)
    {
        cout << nums[i] << ' ';
    }

    return 0;
}
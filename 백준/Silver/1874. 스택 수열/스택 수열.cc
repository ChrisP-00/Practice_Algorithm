#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; 

    vector<int> sequence(n);
    for(int idx = 0; idx < n; ++idx)
    {
        cin >> sequence[idx];
    }

    stack<int> s; 
    vector<char> commands;
    int cur = 1;
    for(int idx = 0; idx < n; ++idx)
    {
        int target = sequence[idx];

        while(cur <= target)
        {
            s.push(cur++);
            commands.push_back('+');
        }

        if(!s.empty() && s.top() == target)
        {
            s.pop();
            commands.push_back('-');
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }

    for(char c : commands)
    {
        cout << c << '\n';
    }

    return 0;
}
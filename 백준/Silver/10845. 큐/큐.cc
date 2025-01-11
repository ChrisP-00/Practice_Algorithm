#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; 
    cin >> tc;

    string command;
    int num;

    queue<int> q;
    while(tc--)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if(command == "pop")
        {
            if(!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(command == "size")
        {
            cout << q.size() << '\n';
        }
        else if(command == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if(command == "front")
        {
            if(!q.empty())
            {
                cout << q.front() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(command == "back")
        {
            if(!q.empty())
            {
                cout << q.back() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
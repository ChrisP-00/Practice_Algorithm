#include <iostream>
#include <stack>

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

    stack<int> stack;
    while(tc--)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> num;
            stack.push(num);
        }
        else if(command == "top")
        {
            if(!stack.empty())
            {
                cout << stack.top() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(command == "pop")
        {
            if(!stack.empty())
            {
                cout << stack.top() << '\n';
                stack.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(command == "size")
        {
            cout << stack.size() << '\n';
        }
        else if(command == "empty")
        {
            cout << stack.empty() << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <unordered_map>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


int main()
{
    fast;
    int n;
    cin >> n;

    unordered_map<int, bool> map;
    while(n--)
    {
        int num;
        cin >> num;
        map[num] = true;
    }

    int m;
    cin >> m;
    while(m--)
    {
        int num;
        cin >> num;
        if(map.count(num) > 0)
        {
            if(map[num])
            {
                cout << 1 << '\n';
            }
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> nameToNum;
    unordered_map<int, string> numToName;

    for(int i = 1; i <= n; ++i)
    {
        cin >> numToName[i];
        nameToNum[numToName[i]] = i;
    }

    for(int i = 0; i < m; ++i)
    {
        string query;
        cin >> query;

        if(isdigit(query[0]))
        {
            int num = stoi(query);
            cout << numToName[num] << '\n';
        }
        else
        {
            cout << nameToNum[query] << '\n';
        }
    }

    return 0;
}
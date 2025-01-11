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

    vector<pair<int, int>> map(n);
    for(int idx = 0; idx < n; ++idx)
    {
        cin >> map[idx].first >> map[idx].second;
    }

    sort(map.begin(), map.end());

    for(auto &p : map)
    {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
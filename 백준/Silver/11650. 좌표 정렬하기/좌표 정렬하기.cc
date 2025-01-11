#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
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
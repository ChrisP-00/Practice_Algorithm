#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int y, int x, vector<vector<int> >& map)
{
    int count = 1; 

    for(int idx = 0; idx < 4; ++idx)
    {
        int ny = y + dir[idx].first;
        int nx = x + dir[idx].second;

        if(ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            if(map[ny][nx] == 1)
            {
                map[ny][nx] = 0;
                count += dfs(ny, nx, map);
            }
        }
    }

    return count;
}


int main()
{
    cin >> n >> m;

    vector<vector<int> > map (n, vector<int>(m, 0));

    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            cin >> map[iy][ix];
        }
    }

    int count = 0, maxNum = 0;

    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            if(map[iy][ix] == 1)
            {
                count++;
                map[iy][ix] = 0;
                maxNum = max(maxNum, dfs(iy, ix, map));
            }
        }
    }

    cout << count << '\n' << maxNum;

    return 0;
}
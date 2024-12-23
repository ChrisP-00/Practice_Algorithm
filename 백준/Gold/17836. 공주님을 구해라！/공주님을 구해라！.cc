#include <iostream> 
#include <queue>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 
using pos = vector<int>;

int n, m, t;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> map;
vector<vector<bool>> isVisited;

int bfs()
{
    queue<pos> q; 
    q.push({0, 0, 0});
    isVisited[0][0] = true;

    int sword = 0;

    while(!q.empty())
    {
        pos cur = q.front();
        q.pop();

        for(int idx = 0; idx < 4; ++idx)
        {
            int ny = cur[0] + dir[idx].first;
            int nx = cur[1] + dir[idx].second;

            if(ny < 0 || ny >= n || nx < 0 || nx >= m 
            || map[ny][nx] == 1 || isVisited[ny][nx])
            {
                continue;
            }
            
            if(ny == n - 1 && nx == m - 1)
            {
                if(sword != 0)
                {
                    return min(cur[2] + 1, sword);
                }
                
                return cur[2] + 1;
            }

            if(map[ny][nx] == 2)
            {
                sword = cur[2] + 1 + (n - ny + m - nx - 2);
            }

            q.push({ny, nx, cur[2] + 1});
            isVisited[ny][nx] = true;
        }
    }

    if(sword != 0)
    {
        return sword;
    }

    return 0;
}

int main()
{
    fast;

    cin >> n >> m >> t;

    map.resize(n, vector<int>(m, 0));
    isVisited.resize(n, vector<bool>(m, false));

    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            cin >> map[iy][ix];
        }
    }

    int answer = bfs();

    if(answer == 0 || answer > t)
    {
        cout << "Fail";
    }
    else
    {
        cout << answer;
    }

    return 0;
}
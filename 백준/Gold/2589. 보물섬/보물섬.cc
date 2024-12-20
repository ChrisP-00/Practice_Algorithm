#include <iostream>
#include <queue>
#include <memory.h>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 
using dii = pair<int, pair<int, int> >;

int n, m;
char map[51][51];
bool isVisited[51][51];
int dirY[4] = {-1, 1, 0, 0};
int dirX[4] = {0, 0, -1, 1};

int bfs(int y, int x)
{
    queue<dii> q; 
    q.push(make_pair(0, make_pair(y, x)));
    isVisited[y][x] = true;

    int depth = 0;

    while(!q.empty())
    {
        int c = q.size();
        depth = max(depth, q.front().first);

        for(int count = 0; count < c; ++count)
        {
            dii cur = q.front();
            q.pop();

            for(int idx = 0; idx < 4; ++idx)
            {
                int ny = cur.second.first + dirY[idx];
                int nx = cur.second.second + dirX[idx];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m 
                || map[ny][nx] == 'W' || isVisited[ny][nx])
                {
                    continue;
                } 

                q.push(make_pair(cur.first + 1, make_pair(ny, nx)));
                isVisited[ny][nx] = true;
            }
        }
    }

    return depth;
}

int main()
{
    fast;
    cin >> n >> m;

    for(int iy = 0; iy < n; ++iy)
    {
        string input; 
        cin >> input;
        for(int ix = 0; ix < m; ++ix)
        {
            map[iy][ix] = input[ix];
        }
    }

    int maxDist = 0;

    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            if(map[iy][ix] == 'L')
            {
                memset(isVisited, false, sizeof(isVisited));
                maxDist = max(maxDist, bfs(iy, ix));
            }
        }
    }

    cout << maxDist;

    return 0;
}
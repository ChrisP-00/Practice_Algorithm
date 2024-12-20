#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std; 

int n, m;
char map[51][51];
vector<vector<bool> > isVisited;
int dirY[4] = {-1, 1, 0, 0};
int dirX[4] = {0, 0, -1, 1};

int bfs(int y, int x)
{
    queue<tuple<int, int, int> > q; 
    q.push(make_tuple(0, y, x));
    isVisited[y][x] = true;

    int depth = 0;

    while(!q.empty())
    {
        int c = q.size();
        depth = max(depth, get<0>(q.front()));

        for(int count = 0; count < c; ++count)
        {
            tuple<int, int, int> cur = q.front();
            q.pop();

            for(int idx = 0; idx < 4; ++idx)
            {
                int ny = get<1>(cur) + dirY[idx];
                int nx = get<2>(cur) + dirX[idx];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m 
                || map[ny][nx] == 'W' || isVisited[ny][nx])
                {
                    continue;
                } 

                q.push(make_tuple(get<0>(cur) + 1, ny, nx));
                isVisited[ny][nx] = true;
            }
        }
    }

    return depth;
}

int main()
{
    cin >> n >> m;

    isVisited.resize(n, vector<bool>(m));

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
                isVisited.assign(n, vector<bool>(m, false));
                maxDist = max(maxDist, bfs(iy, ix));
            }
        }
    }

    cout << maxDist;

    return 0;
}

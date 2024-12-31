#include <iostream>
#include <queue>

using namespace std; 

int dirY[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dirX[8]  = {0, 0, -1, 1, -1, 1, -1, 1};
int map[51][51];

int bfs(int y, int x, int w, int h)
{
    int count = 0;

    queue<pair<int, int>> q; 

    q.push({y, x});

    while(!q.empty())
    {
        auto[cy, cx] = q.front();
        q.pop();

        for(int idx = 0; idx < 8; ++idx)
        {
            int ny = cy + dirY[idx];
            int nx = cx + dirX[idx];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w || map[ny][nx] == 0)
            {
                continue; 
            }

            q.push({ny, nx});
            map[ny][nx] = 0;
        }
    }

    return count; 
}

int countIsland(int w, int h)
{
    int count = 0;

    for(int iy = 0; iy < h; ++iy)
    {
        for(int ix = 0; ix < w; ++ix)
        {
            if(map[iy][ix])
            {
                bfs(iy, ix, w, h);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    while(true)
    {
        int w, h;
        cin >> w >> h;
        
        if(w == 0 && h == 0)
        {
            break;
        }

        for(int iy = 0; iy < h; ++iy)
        {
            for(int ix = 0; ix < w; ++ix)
            {
                cin >> map[iy][ix];
            }
        }

        cout << countIsland(w, h) << '\n';
    }

    return 0;
}
#include <iostream> 

using namespace std; 

char map[251][251];
int dirY[4] = {-1, 1, 0, 0};
int dirX[4] = {0, 0, -1, 1};
int n, m;
int sheep = 0, wolf = 0;

void whoSurvive(int y, int x, int& s, int& w)
{
    if(map[y][x] == 'v')
    {
        w++;
    }
    else if(map[y][x] == 'k')
    {
        s++;
    }
    
    map[y][x] = '#';
    for(int dir = 0; dir < 4; ++dir)
    {
        int ny = y + dirY[dir];
        int nx = x + dirX[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#')
        {
            continue; 
        }
        whoSurvive(ny, nx, s, w);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    cin >> n >> m;
    for(int iy = 0; iy < n; iy++)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            cin >> map[iy][ix];
        }
    }
    
    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            if(map[iy][ix] != '#')
            {
                int s = 0, w = 0;
                whoSurvive(iy, ix, s, w);
                
                if(s > w)
                {
                    sheep += s;
                }
                else
                {
                    wolf += w;
                }
            }
        }
    }
    
    cout << sheep << ' ' << wolf;
    
    return 0;
}
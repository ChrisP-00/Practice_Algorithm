#include <iostream> 
#include <queue>
#include <vector> 

using namespace std;

int n, m;

int dirY[4] = {-1, 1, 0, 0};
int dirX[4] = {0, 0, -1, 1};
bool isVisited [1001][1001];

vector<vector<int> > map;
vector<vector<int> > dist;

void bfs(int y, int x)
{
    queue<pair<int, pair<int,int> > > q; 
    q.push(make_pair(0, make_pair(y, x)));

    isVisited[y][x] = true;
    dist[y][x] = 0;

    while(!q.empty())
    {
        pair<int, pair<int,int> >  cur = q.front();
        q.pop();
        
        for(int idx = 0; idx < 4; ++idx)
        {
            int ny = cur.second.first + dirY[idx];
            int nx = cur.second.second + dirX[idx];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m 
            || isVisited[ny][nx] || map[ny][nx] == 0)
            {
                continue;
            }

            dist[ny][nx] = cur.first + 1;
            isVisited[ny][nx] = true;

            q.push(make_pair(dist[ny][nx], make_pair(ny, nx)));
        }
    }
}


int main()
{
    cin >> n >> m;

    map.resize(n, vector<int>(m, 0));
    dist.resize(n, vector<int>(m, false));

    int by, bx;

    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            cin >> map[iy][ix];

            if(map[iy][ix] == 2)
            {
                by = iy;
                bx = ix;
            }
        }
    }
    
    bfs(by, bx);
    
    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {

            if(isVisited[iy][ix])
            {
               cout << dist[iy][ix] << ' ';
            }
            else
            {
                if(map[iy][ix] == 0)
                {
                    cout << "0 ";
                }
                else
                {
                    cout << "-1 ";
                }
            }
        }

        cout << '\n';
    }
    
    return 0;
}
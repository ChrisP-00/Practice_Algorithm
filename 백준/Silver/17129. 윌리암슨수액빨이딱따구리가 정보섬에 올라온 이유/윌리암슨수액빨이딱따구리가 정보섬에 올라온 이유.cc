#include <iostream> 
#include <vector> 
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0 , 1}};

void bfs(int y, int x)
{
    int count = 0; 
    queue<pair<int, int>> q; 
    vector<vector<bool>> isVisited (n, vector<bool>(m, false));
    
    q.push({y,x});
    isVisited[y][x] = true;


    bool isMoved = false;
    while(!q.empty())
    {        
        int qCount = q.size();

        for(int i = 0; i < qCount; ++i)
        {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            if(map[cy][cx] >= 3 && map[cy][cx] <= 5)
            {
                cout << "TAK\n" << count;
                return;
            }

            for(int idx = 0; idx < 4; ++idx)
            {
                int ny = cy + dir[idx].first;
                int nx = cx + dir[idx].second;
                
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || isVisited[ny][nx] || map[ny][nx] == 1)
                {
                    continue; 
                }

                q.push({ny, nx});
                isVisited[ny][nx] = true;
            }
        }

        count++;

    }

    cout << "NIE";
}


int main()
{
    cin >> n >> m;
    
    map.resize(n, vector<int>(m, 0));
    
    pair<int, int> start;

    for(int iy = 0; iy < n; ++iy)
    {
        string s;
        cin >> s;

        for(int ix = 0; ix < m; ++ix)
        {
            map[iy][ix] = s[ix] - '0';

            if(map[iy][ix] == 2)
            {
                start = {iy, ix};
            }
        }
    }

    bfs(start.first, start.second);
    
    return 0;
}
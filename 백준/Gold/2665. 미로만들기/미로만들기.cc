#include <iostream> 
#include <deque>
#include <vector>

using namespace std;

int n;
vector<vector<int> > map;
vector<vector<bool> > isVisited;

int dirY[4] = {-1, 1, 0, 0};
int dirX[4] = {0, 0, -1, 1};

int bfs()
{
    deque<pair<int, pair<int, int> > > d; 
    d.push_front(make_pair(0, make_pair(0, 0)));
    isVisited[0][0] = true;

    while(!d.empty())
    {
        pair<int, pair<int, int> > cur = d.front();
        d.pop_front();

        for(int idx = 0; idx < 4; ++idx)
        {
            int ny = cur.second.first + dirY[idx];
            int nx = cur.second.second + dirX[idx];

            if(ny == n - 1 && nx == n -1)
            {
                return cur.first;
            }

            if(ny < 0 || ny >= n || nx < 0 || nx >= n || isVisited[ny][nx])
            {
                continue;
            }

            if(map[ny][nx] == 1)
            {
                d.push_front(make_pair(cur.first, make_pair(ny, nx)));
            }
            else
            {
                d.push_back(make_pair(cur.first + 1, make_pair(ny, nx)));
            }

            isVisited[ny][nx] = true;
        }

    }

    return -1;
}


int main()
{
    cin >> n;

    map.resize(n, vector<int>(n, 0));
    isVisited.resize(n, vector<bool>(n, false));

    for(int iy = 0; iy < n; ++iy)
    {
        string input; 
        cin >> input;

        for(int ix = 0; ix < n; ++ix)
        {
            map[iy][ix] = input[ix] - '0';
        }
    }

    cout << bfs();

    return 0;
}
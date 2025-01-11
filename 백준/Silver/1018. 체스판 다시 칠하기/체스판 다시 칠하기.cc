#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


vector<vector<char>> map;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int check(int by, int bx, char color)
{
    int repaint = 0;
    char curColor = color; 

    for(int iy = 0; iy < 8; ++iy)
    {
        for(int ix = 0; ix < 8; ++ix)
        {
            if(map[by + iy][bx + ix] != curColor)
            {
                repaint++;
            }

            curColor = (curColor == 'B') ? 'W' : 'B';
        }

        curColor = (curColor == 'B') ? 'W' : 'B';
    }

    return repaint;
}


int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    map.resize(n, vector<char>(m));


    for(int iy = 0; iy < n; ++iy)
    {
        for(int ix = 0; ix < m; ++ix)
        {
            cin >> map[iy][ix];
        }
    }

    int ans = 50;

    for(int iy = 0; iy <= n - 8; ++iy)
    {
        for(int ix = 0; ix <= m - 8; ++ix)
        {
            int bw = check(iy, ix, 'B');
            int wb = check(iy, ix, 'W');
            ans = min(ans, min(bw, wb));
        }
    }

    cout << ans;

    return 0;
}
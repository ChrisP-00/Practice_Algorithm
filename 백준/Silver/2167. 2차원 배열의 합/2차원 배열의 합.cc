#include <iostream> 
#include <vector>

using namespace std; 

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > map (302, vector<int>(302, 0));
    
    for(int iy = 1; iy <= n; ++iy)
    {
        for(int ix = 1; ix <= m; ++ix)
        {
            int input; 
            cin >> input; 
 
            map[iy][ix] = input + map[iy][ix - 1];
        }
    }
    
    int t; 
    cin >> t; 
    
    while(t--)
    {
        int by, bx, ey, ex; 
        cin >> by >> bx >> ey >> ex; 
        
        int sum = 0;
        
        for(int ty = by; ty <= ey; ++ty)
        {
            sum += map[ty][ex] - map[ty][bx - 1];
        }
        
        cout << sum << '\n';
    }
    
    return 0;
}
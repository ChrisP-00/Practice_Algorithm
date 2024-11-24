#include <iostream> 
#include <vector>

using namespace std; 

int main()
{
    int t;
    cin >> t;

    vector<vector<int>> apt (15, vector<int>(15, 0));

    for(int j = 1; j < 15; ++j)
    {
        apt[0][j] = j;
    }

    for(int i = 1; i < 15; ++i)
    {
        for(int j = 1; j < 15; ++j)
        {
            apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
        }
    }

    while(t--)
    {
        int k, n; 
        cin >> k >> n;

        cout << apt[k][n] << '\n';
    } 

    return 0;
}
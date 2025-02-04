#include <iostream> 

using namespace std;

int DP[1000001];
int PATH[1000001];

int main()
{
    int n = 0;
    cin >> n;

    DP[1] = 0;

    for(int idx = 2; idx <= n; idx++)
    {
        DP[idx] = DP[idx - 1] + 1; 
        PATH[idx] = idx - 1;

        if(idx % 3 == 0 && DP[idx] > DP[idx / 3] + 1)
        {
            DP[idx] = DP[idx / 3] + 1;
            PATH[idx] = idx / 3;
        }

        if(idx % 2 == 0 && DP[idx] > DP[idx / 2] + 1)
        {
            DP[idx] = DP[idx / 2] + 1;
            PATH[idx] = idx / 2;
        }
    }

    cout << DP[n] << '\n';
    
    while(n != 0)
    {
        cout << n << ' ';
        n = PATH[n];
    }
    return 0;
}
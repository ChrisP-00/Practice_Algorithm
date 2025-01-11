#include <iostream>
#include <vector>

using namespace std;

void findPrimes(int n, int m)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; ++i)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for(int i = m; i <= n; ++i)
    {
        if(isPrime[i])
        {
            cout << i << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> m >> n;

    findPrimes(n, m);

    return 0;
}
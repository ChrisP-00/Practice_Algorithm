#include <iostream>
#include <vector>

using namespace std;

void findPrimes(int n, int m)
{
    int size = (n / 2) + 1;
    vector<bool> isPrime(size, true);
    isPrime[0] = false;

    for(int i = 3; i * i <= n; i += 2)
    {
        if(isPrime[i / 2])
        {
            for(int j = i * i; j <= n; j += i * 2)
            {
                isPrime[j / 2] = false;
            }
        }
    }

    if(m <= 2 && n >= 2) cout << 2 << '\n';
    if(m % 2 == 0)
    {
        m++;
    }

    for(int i = m; i <= n; i += 2)
    {
        if(isPrime[i / 2])
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
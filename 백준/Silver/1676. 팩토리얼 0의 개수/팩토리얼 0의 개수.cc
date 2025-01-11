#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    int count = 0;
    while(n > 0)
    {
        count += n / 5;
        n /= 5;
    }

    cout << count;

    return 0;
}
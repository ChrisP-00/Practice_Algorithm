#include <iostream> 

using namespace std; 

int fac (int n)
{
    int a = 1;

    for(int i = 2; i <= n; ++i)
    {
        a *= i;
    }

    return a;
}



int main()
{
    int n, k; 
    cin >> n >> k;

    cout << fac(n) / (fac(n - k) * fac(k));

    return 0;
}
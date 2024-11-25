#include <iostream> 

using namespace std; 

int findGCD(int a, int b)
{
    return b ? findGCD(b, a % b) : a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    int lcm, gcd;

    gcd = findGCD(a, b);
    lcm = (a * b) / gcd;

    cout << gcd << '\n' << lcm;
    
    return 0;
}
#include <iostream>

using namespace std; 

int main()
{
    int n, count = 0; 
    cin >> n;

    count += n / 5;
    n = n % 5 ;

    while(count >= 0)
    {
        if(n % 2 == 0)
        {
            count += n / 2;
            break;
        }

        count--;
        n += 5;
    }

    cout << (count > 0 ? count : -1); 

    return 0;
}
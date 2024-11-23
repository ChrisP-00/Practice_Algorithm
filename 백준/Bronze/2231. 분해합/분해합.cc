#include <iostream> 

using namespace std; 

int main()
{
    int n; 
    cin >> n;

    int ans = 0;
    for(int idx = n; idx > 0; --idx)
    {
        int target = idx;
        int num = idx;

        while(num > 0)
        {
            target += num % 10;
            num /= 10;
        }

        if(target == n)
        {   
            ans = idx; 
        }
    }

    cout << ans;

    return 0;
}
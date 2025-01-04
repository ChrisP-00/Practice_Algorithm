#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int sum = 0, ans = -100000000, num;  
    for(int idx = 0; idx < n; ++idx)
    {
        cin >> num;
        
        sum = max(sum + num, num);
        ans = max(sum, ans);
    }
    
    cout << ans;
    
    return 0;
}
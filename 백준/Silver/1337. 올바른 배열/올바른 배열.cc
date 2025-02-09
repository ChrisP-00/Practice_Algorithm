#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std; 

vector<int> myV;

int main()
{
    int n; 
    int ans = 4;
    cin >> n;

    myV.assign(n,0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> myV[idx];
    }

    sort(myV.begin(), myV.end());

    for(int st = 0; st < n; st++)
    {
        int en = n - 1;
        while(st < en)
        {  
            if(myV[en] - myV[st] > 4) 
            {
                en--;
            }
            else
            {
                ans = min(ans, 4 - (en - st));
                break;
            }
        }
    }

    cout << ans;

    return 0;
}

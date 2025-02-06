#include <iostream> 
#include <vector> 

using namespace std; 

vector<int> sushi;
vector<int> hasEaten (3001);

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    sushi.assign(n, 0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> sushi[idx];
    }

    int cnt = 0, ans = 0; 

    for(int idx = 0; idx < k; idx++)
    {
        if(!hasEaten[sushi[idx]])
        {
            cnt++;
        }
        hasEaten[sushi[idx]]++;
    } 

    if(hasEaten[c] == 0) 
    {
        ans = cnt + 1;
    }
    else 
    {
        ans = cnt;
    }

    int en = 0;

    for(int st = 1; st < n; st++)
    {
        en = (st + k - 1) % n; 

        if(hasEaten[sushi[en]] == 0)
        {
            cnt++;
        }
        hasEaten[sushi[en]]++;
        
        hasEaten[sushi[st - 1]]--;
        if(hasEaten[sushi[st - 1]] == 0) 
        {
            cnt--;
        }

        if(ans <= cnt)
        {
            if(hasEaten[c] == 0) 
                ans = cnt + 1;
            else 
            {
                ans = cnt;
            }
        }
    }
    
    cout << ans;

    return 0;
}
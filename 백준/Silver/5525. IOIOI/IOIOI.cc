#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n, m;
    string s;
    cin >> n >> m >> s;

    int ans = 0, count = 0;
    for(int i = 1; i < m - 1; ++i)
    {
        if(s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I')
        {
            count++;

            if(count >= n) 
            {
                ans++;
            }
            i++;
        }
        else 
        {
            count = 0;
        }
    }
    
    cout << ans;

    return 0;
}
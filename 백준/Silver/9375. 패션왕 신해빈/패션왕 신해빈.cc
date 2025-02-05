#include <iostream> 
#include <unordered_map> 

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        unordered_map<string, int> closes;        
        while(n--)
        {
            string name, type;
            cin >> name >> type;

            closes[type]++;
        }

        int ans = 1;
        for(auto[a, b] : closes)
        {
            ans *= b + 1;
        }

        cout << ans - 1 << '\n';
    }

    return 0;
}

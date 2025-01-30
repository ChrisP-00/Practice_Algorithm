#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> p (n, 0);

    for(int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += p[i] * (n - i);
    }

    cout << ans;

    return 0;
}
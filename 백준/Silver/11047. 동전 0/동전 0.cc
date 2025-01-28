#include <iostream> 
#include <vector> 

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, target; 
    cin >> n >> target; 

    vector<int> changes (n, 0);

    for(int i = 0; i < n; ++i) {
        cin >> changes[i];
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(changes[i] > target) continue; 

        ans += target / changes[i];
        target %= changes[i];
    }

    cout << ans;

    return 0;
}
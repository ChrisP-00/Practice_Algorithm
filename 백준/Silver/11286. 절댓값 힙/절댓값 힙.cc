#include <iostream> 
#include <queue>

using namespace std;

typedef long long ll;

ll absolute(ll a)
{
    return (a > 0) ? a : -a;
}

int main()
{
    int n;
    cin >> n;
    

    priority_queue<pair<ll,ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    while(n--)
    {
        ll num;
        cin >> num;

        if(num != 0)
        {
            pq.push({absolute(num), num});
        }
        else
        {
            if(!pq.empty())
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else
            {
                cout << "0\n";
            }
        }
    }

    return 0;
}
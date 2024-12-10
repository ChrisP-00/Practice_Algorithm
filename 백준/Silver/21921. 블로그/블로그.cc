#include <iostream> 
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std; 

int main ()
{
    fast;

    int people [250001];
    
    int n, x;
    cin >> n >> x; 
    
    int sum = 0;
    for(int idx = 0; idx < n; ++idx)
    {
        cin >> people[idx];

        if(idx < x)
        {
            sum += people[idx];
        }
    }
    
    int maxValue = sum;
    int count = 1;

    for(int idx = x; idx < n; ++idx)
    {
        sum -= people[idx - x];
        sum += people[idx];

        if(maxValue < sum)
        {
            maxValue = sum;
            count = 1;
        }
        
        else if(maxValue == sum)
        {
            count++;
        }

    }

    if(maxValue == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << maxValue << '\n' << count;
    }
    
    return 0;
}
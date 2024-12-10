#include <iostream> 

using namespace std; 

int main ()
{
    int people [250001];
    
    int n, x;
    cin >> n >> x; 
    
    int maxValue = 0;
    int sum = 0;
    for(int idx = 0; idx < n; ++idx)
    {
        cin >> people[idx];

        if(idx < x)
        {
            sum += people[idx];
        }
    }
    
    int count = 1;
    if(n > 1)
    {
        for(int idx = x; idx <= n; ++idx)
        {
            
            if(maxValue < sum)
            {
                maxValue = sum;
                count = 1;
            }
            
            else if(maxValue == sum)
            {
                count++;
            }

            sum -= people[idx - x];
            sum += people[idx];
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
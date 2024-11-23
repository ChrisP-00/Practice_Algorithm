#include <iostream> 
#include <vector> 

using namespace std; 

int main()
{
    int n; 
    cin >> n;
    
    vector<int> tShirts (6, 0);
  
    for(int idx = 0; idx < 6; ++idx)
    {
        cin >> tShirts[idx];
    }
    
    int t, p;
    cin >> t >> p;
    
    int tCount = 0;
    
    for(int idx = 0; idx < 6; ++idx)
    {
        if(tShirts[idx] % t != 0)
        {
            tCount += 1;
        }
        
        tCount += tShirts[idx] / t;
    }
    

   
    cout << tCount << '\n';
    cout << n / p << ' ' << n % p;    
    return 0;
}

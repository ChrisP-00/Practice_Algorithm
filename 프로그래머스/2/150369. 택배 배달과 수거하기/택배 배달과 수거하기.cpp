#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int dw = 0;
    int pw = 0;
    int idx = n - 1;
    
    while(true)
    {
        if(idx < 0)
        {
            break;
        }
        dw += deliveries[idx];
        pw += pickups[idx];
        
        int count = 0;
        while(dw > 0 || pw > 0)
        {
            dw -= cap; 
            pw -= cap; 
            count++; 
        }
        
        answer += (idx + 1) * 2 * count; 
        
        idx--;
    }
    
    return answer;
} 
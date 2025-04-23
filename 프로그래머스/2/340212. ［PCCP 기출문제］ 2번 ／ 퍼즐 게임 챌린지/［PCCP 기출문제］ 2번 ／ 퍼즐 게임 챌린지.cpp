#include <string>
#include <vector>
#include <limits>

using namespace std;

bool isPass(int level, const vector<int>& diffs, const vector<int>& times, const long long& limit)
{
    long long ttl = 0;
    
    for(int i = 0; i < diffs.size(); ++i)
    {
        if(level >= diffs[i])
        {
            ttl += times[i];
        }
        else
        {
            ttl += (long long)(times[i] + times[i-1]) * (diffs[i] - level) + times[i];
        }
        
        if(ttl > limit)
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100001;
    int l = 1;
    int r = 100000;
    
    while(l <= r)
    {
        int mid = (l + r) / 2;
            
        if(isPass(mid, diffs, times, limit))
        {
            r = mid - 1;
            answer = min(mid, answer);
        }
        else
        {
            l = mid + 1;
        }
    }
    
    
    
    
    return answer;
}
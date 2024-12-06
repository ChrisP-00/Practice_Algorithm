#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> counts (32, 0);
    vector<int> rev = reserve;
    
    for(int n : lost)
    {
        counts[n]--;
    }

    for(int r : reserve)
    {
        counts[r]++;
    }    
    
    for(int idx = 0; idx <= n; ++idx)
    {
        if(counts[idx] != 1)
        {
            continue;
        }

        else if(counts[idx - 1] == -1)
        {
            counts[idx - 1] = 0;
            continue; 
        }
        else if(counts[idx + 1] == -1)
        {
            counts[idx + 1] = 0;
            continue;
        }
    }
    
    answer = n;
    
    for(int c : counts)
    {
       if(c < 0)
       {
           answer += c;
       }
    }
    
    return answer;
}
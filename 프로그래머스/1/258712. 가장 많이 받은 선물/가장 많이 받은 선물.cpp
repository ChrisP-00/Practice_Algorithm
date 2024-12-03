#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    unordered_map<string, unordered_map<string, int> > myMap; 
    unordered_map<string, int> rate; 
    
    for(string name : gifts)
    {
        stringstream ss (name);
        string a, b; 
        // a는 준 애, b는 받은 애
        ss >> a >> b;
        
        rate[a]++;
        rate[b]--;
        
        // 누가 누구한테 줬는지 기록
        myMap[a][b]++;
    }

    
    for(string sender : friends)
    {
        int count = 0;
        for(string receiver : friends)
        {
            if(sender == receiver)
            {
                continue;
            }
            
            // 보낸게 많음
            if(myMap[sender][receiver] > myMap[receiver][sender])
            {
                count++;
            }
            else if(myMap[sender][receiver] == myMap[receiver][sender])
            {
                if(rate[sender] > rate[receiver])
                {
                    count++;
                }
            }
            
            answer = max(answer, count);
        }
    }
    
    return answer;
}
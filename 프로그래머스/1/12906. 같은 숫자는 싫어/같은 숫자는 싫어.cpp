#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
 
    if(arr.empty())
    {
        return answer;
    }
    
    answer.push_back(arr[0]);
     
    for(int idx = 1; idx < arr.size(); ++idx)
    {
        if(arr[idx] != arr[idx - 1])
        {
            answer.push_back(arr[idx]);
        }
    }
    
    return answer;
}
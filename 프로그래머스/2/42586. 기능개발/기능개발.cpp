#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(!progresses.empty())
    {
        for(int idx = 0; idx < progresses.size(); ++idx)
        {
            progresses[idx] += speeds[idx];
        } 
        
        int completed = 0;
        while(!progresses.empty() && progresses[0] >= 100)
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            completed++;
        }
        
        if(completed > 0)
        {
            answer.push_back(completed);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(auto& q : queries)
    {
        vector<int> temp(arr.begin() + q[0], arr.begin() + q[1] + 1);
        sort(temp.begin(), temp.end());
        
        auto it = upper_bound(temp.begin(), temp.end(), q[2]);
        answer.push_back(it != temp.end() ? *it : -1);
    }
    
    return answer;
}
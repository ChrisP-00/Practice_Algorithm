#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& nums, const int& target, int idx, int sum)
{
    if(idx == nums.size())
    {
        return sum == target ? 1 : 0;
    }

    int plus = dfs(nums, target, idx + 1, sum + nums[idx]);
    int minus = dfs(nums, target, idx + 1, sum - nums[idx]);
    
    return plus + minus;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(numbers, target, 0, 0);
    
    return answer;
}
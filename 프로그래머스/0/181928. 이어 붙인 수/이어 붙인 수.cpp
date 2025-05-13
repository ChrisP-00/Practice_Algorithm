#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    auto[odd, even] = accumulate(num_list.begin(), num_list.end(), pair<string, string>{}, 
     [](pair<string, string> nums, int x){
        if(x % 2) nums.first += to_string(x);
        else nums.second += to_string(x);
        return nums;
    });
    
    return stoi(odd) + stoi(even);
}
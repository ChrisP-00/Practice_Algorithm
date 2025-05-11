#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    return (accumulate(num_list.begin(), num_list.end(), 1, [](int sum, int a){
                return sum *= a; }) <
            pow(accumulate(num_list.begin(), num_list.end(), 0), 2));
}
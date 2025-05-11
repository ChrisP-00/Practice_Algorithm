#include <unordered_set>
#include <cmath>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    unordered_set<int> nums = {a, b, c};
    
    switch (nums.size()) {
        case 1: {
            int sum1 = a + b + c;
            int sum2 = a * a + b * b + c * c;
            int sum3 = a * a * a + b * b * b + c * c * c;
            return sum1 * sum2 * sum3;
        }
        case 2: {
            int sum1 = a + b + c;
            int sum2 = a * a + b * b + c * c;
            return sum1 * sum2;
        }
        case 3:
            return a + b + c;
    }

    return 0;
}
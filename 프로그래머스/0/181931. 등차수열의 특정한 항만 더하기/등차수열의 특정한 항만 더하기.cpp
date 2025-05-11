#include <numeric>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> v) {
    int i = 0;
    return accumulate(v.begin(), v.end(), 0, [&](int sum, bool flag) {
        int result = flag ? a + d * i : 0;
        ++i;
        return sum + result;
    });
}
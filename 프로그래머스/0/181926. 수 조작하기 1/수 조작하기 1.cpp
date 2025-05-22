#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> cal = {{'w', 1}, {'s', -1}, {'d', 10}, {'a', -10}};

int solution(int n, string control) {
    for(char c : control)
    {
        n += cal[c];
    }
    return n;
}
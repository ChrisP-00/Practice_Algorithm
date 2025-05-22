#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, char> cal = {{1, 'w'}, {-1, 's'}, {10, 'd'}, {-10, 'a'}};

string solution(vector<int> numLog) {
    string answer = "";

    for(int i = 1; i < numLog.size(); ++i)
    {
        answer += cal[numLog[i] - numLog[i - 1]];
    }
    
    return answer;
}
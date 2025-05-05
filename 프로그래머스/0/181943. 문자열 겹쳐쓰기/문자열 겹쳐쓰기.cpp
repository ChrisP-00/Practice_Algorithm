#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    
    copy(overwrite_string.begin(), overwrite_string.end(), answer.begin() + s);
    return answer;
}
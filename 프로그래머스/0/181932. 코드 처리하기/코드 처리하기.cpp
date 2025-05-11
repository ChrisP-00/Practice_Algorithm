#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    
    for(int i = 0; i < code.length(); ++i)
    {
        if((code[i] - '0') < 2)
        {
            mode ^= code[i] - '0';
            continue;
        }
        
        if((!mode && !(i % 2)) || ((mode && i % 2)))
        {
            answer += code[i];
        }
    }
    
    return answer.empty() ? "EMPTY" : answer;
}
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int count = 0;

    for(int idx = 0; idx < s.size(); ++idx)
    {
        if(s[idx] == '(')
        {
            count++;
        }
        
        else if(s[idx] == ')')
        {
            count--;
        }
        
        if(count < 0)
        {
            return false;
        }
    }

    return count == 0;
}
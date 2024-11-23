#include <iostream> 
#include <string>

using namespace std; 


bool isNum(string input)
{
    int start = 0;
    int end = input.length() - 1;

    while(start < end)
    {

        if(input[start] != input[end])
        {
            return false; 
        }

        start++;
        end--;
    }

    return true; 
}

int main()
{
    string input = "";

    while(true)
    {
        cin >> input; 

        if(input == "0")
        {
            break;
        }

        if(isNum(input))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

  
    return 0;
}
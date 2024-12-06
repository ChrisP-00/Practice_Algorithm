#include <iostream>
#include <string>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int isNum(string s)
{
    if(s == "Fizz" || s == "Buzz" || s == "FizzBuzz")
    {
        return 0;
    }

    return stoi(s);
}

string Fizzz(int n)
{
    if(n % 15 == 0)
    {
        return "FizzBuzz";
    }
    else if(n % 3 == 0)
    {
        return "Fizz";
    }
    else if(n % 5 == 0)
    {
        return "Buzz";
    }

    return to_string(n);
}

int main()
{
    fast; 

    vector<string> inputs(3, "");
    cin >> inputs[0] >> inputs[1] >> inputs[2];

    for(int idx = 0; idx < 3; ++idx)
    {
        int n = isNum(inputs[idx]);

        if(n)
        {
            cout << Fizzz(n + 3 - idx);
            return 0;
        }
    }

    cout << "Hello World";

    return 0;
}
#include <iostream>
#include <string> 
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

const string shom = "666";

bool isContainSix(int n)
{
    string s = to_string(n);
    return s.find(shom) != string::npos;   
}

int main()
{
    fast;
    
    int n; 
    cin >> n;

    int name = 666;
    while(n > 0)
    {
        if(isContainSix(name))
        {
            n--;
        }

        name++;
    }

    cout << name -1;

    return 0;
}
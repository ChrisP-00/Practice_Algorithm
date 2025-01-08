#include <iostream>
#include <unordered_map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main()
{
    fast; 
    
    unordered_map<string, string> passwords;
    int ws, pw;
    
    cin >> ws >> pw; 
    
    for(int idx = 0; idx < ws; ++idx)
    {
        string a, b; 
        cin >> a >> b;
        
        passwords[a] = b;
    }
    
    for(int idx = 0; idx < pw; ++idx)
    {
        string input; 
        cin >> input; 
        
        cout << passwords[input] << '\n';
    }
        
    return 0;
}

#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int n; 
    cin >> n;

    vector<pair<int, string>> inputs; 
   
    while(n--)
    {
        string s; 
        cin >> s;

        inputs.push_back(make_pair(s.length(), s));     
    }

    sort(inputs.begin(), inputs.end());
    inputs.erase(unique(inputs.begin(), inputs.end()), inputs.end());

    for(auto n : inputs)
    {
        cout << n.second << '\n';
    }

    return 0;
}
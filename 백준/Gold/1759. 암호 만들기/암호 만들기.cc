#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

int l, c;
vector<char> alphabets;
vector<string> ans;

bool isAcceptable(string &s)
{
    int vowels = 0, consonants = 0;
    
    for(const char ch : s)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }

    return vowels >= 1 && consonants >= 2;
}



void makeCode(string word, int idx)
{
    if(word.size() == l)
    {
        if(isAcceptable(word))
        {
            ans.push_back(word);
        }
        return;
    }
    
    for(int i = idx; i < c; ++i)
    {
        makeCode(word + alphabets[i], i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> l >> c;
    
    alphabets.resize(c);
    for(int idx = 0; idx < c; ++idx)
    {
        cin >> alphabets[idx];
    }
    
    sort(alphabets.begin(), alphabets.end());
    makeCode("", 0);

    for(const string& s : ans)
    {
        cout << s << '\n';
    }
    
    return 0;
}
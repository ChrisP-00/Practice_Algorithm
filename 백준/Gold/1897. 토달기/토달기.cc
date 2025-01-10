#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    fast;
    int n;
    string word;

    cin >> n >> word; 

    vector<string> words;

    while(n--)
    {
        string w;
        cin >> w;
        words.push_back(w);
    }

    sort(words.begin(), words.end(), [](const string& a, const string& b)
    {
        return a.size() < b.size();    
    });

    unordered_map<string, bool> wMap;
    wMap[word] = true;
    string maxWord = word;

    for(const string& curWord : words)
    {
        for(int idx = 0; idx < curWord.size(); ++idx)
        {
            string shorten = curWord; 
            shorten.erase(shorten.begin() + idx);

            if(wMap.count(shorten) > 0 && wMap[shorten])
            {
                wMap[curWord] = true;

                if(curWord.size() > maxWord.size())
                {
                    maxWord = curWord;
                }
            }
        }  
    }

    cout << maxWord;

    return 0;
}
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int see, listen; 
    cin >> see >> listen;

    unordered_set<string> mySet;
    vector<string> noSeeNoListen;

    while(see--) {
        string s;
        cin >> s;

        mySet.insert(s);
    }

    while(listen--) {
        string s;
        cin >> s;

        if(mySet.find(s) != mySet.end()) {
            noSeeNoListen.push_back(s);
        }
    }

    sort(noSeeNoListen.begin(), noSeeNoListen.end());

    cout << noSeeNoListen.size() << '\n';

    for(auto name : noSeeNoListen) {
        cout << name << '\n';    
    }

    return 0;
}

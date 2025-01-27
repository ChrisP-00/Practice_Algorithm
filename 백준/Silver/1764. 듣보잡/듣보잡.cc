#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int see, listen; 
    cin >> see >> listen;

    map<string, int> noSeeNoListen;
    int count = 0;
    for(int i = 0; i < see + listen; ++i) {
        string s;
        cin >> s;
        noSeeNoListen[s]++;

        if(noSeeNoListen[s] > 1) {
            count++;
        }
    }

    cout << count << '\n';

    for(auto&[a, b] : noSeeNoListen) {
        if(b > 1) {
            cout << a << '\n';
        }
    }

    return 0;
}

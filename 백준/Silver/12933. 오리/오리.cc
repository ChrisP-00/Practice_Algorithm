#include <iostream>
#include <vector>
#include <string>

using namespace std;

int quackToInt(const char& c) {
    switch (c) {
        case 'q': return 0;
        case 'u': return 1;
        case 'a': return 2;
        case 'c': return 3;
        case 'k': return 4;
        default: return -1;
    }
}

int findDuck(const string& s) {
    vector<int> ducks;
    int duckCount = 0;

    for (const char& c : s) {
        int curDuck = quackToInt(c);

        if(curDuck == -1)
        {
            return -1;
        }

        bool foundDuckSound = false;
        for (int& duck : ducks) {
            if (duck == curDuck - 1) {
                duck = curDuck;
                foundDuckSound = true;

                if(duck == 4)
                {
                    duck = -1;
                }
                break;
            }
        }

        if (!foundDuckSound) {
            if (curDuck == 0) {
                ducks.push_back(0);
            }
            else
            {
                return -1;
            }
        }

        duckCount = max(duckCount, static_cast<int>(ducks.size()));
    }

    for(int& duck : ducks)
    {
        if(duck != -1)
        {
            return -1;
        }
    }

    return duckCount;
}

int main() {
    string s;
    cin >> s;

    int result = findDuck(s);
    cout << result << endl;

    return 0;
}

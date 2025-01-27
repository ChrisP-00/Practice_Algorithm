#include <iostream> 
#include <queue>
#include <algorithm>

using namespace std;

class comp {
    public:
    bool operator()(int a, int b) {
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};


int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, comp > pq;
    while(n--) {
        int num;
        cin >> num;

        if(num != 0) {
            pq.push(num);
        }
        else {
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << "0\n";
            }
        }
    }

    return 0;
}
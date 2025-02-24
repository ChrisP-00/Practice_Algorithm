#include <iostream>
#include <deque>
#include <string>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;

int Q, Dir = 0, B = 0, W = 0;
deque<char> DQ;
string S;
char C;

void input() {
    cin >> Q;
    while (Q--) {
        cin >> S;

        if (S == "push") {
            cin >> C;
            
            if ((Dir == 0) || (Dir == 2) || (Dir == 1 && C == 'w') || (Dir == 3 && C == 'w')) {
                DQ.push_front(C);
                if (C == 'b') B++;
                else if (C == 'w') W++;
            } 
            else if (Dir == 1 && C == 'b') {
                if (!DQ.empty() && DQ.back() == 'w') {
                    DQ.push_front(C);
                    B++;
                }
            }
        } 

        else if (S == "pop" && !DQ.empty()) {
            char item = DQ.back();
            DQ.pop_back();

            if (item == 'b') B--;
            else if (item == 'w') W--;

            if (item == 'w' && Dir == 1) {
                while (!DQ.empty() && DQ.back() == 'b') {
                    DQ.pop_back();
                    B--;
                }
            } 
        }

        else if (S == "rotate") {
            cin >> C;
            if (C == 'l') {
                Dir = (Dir + 3) % 4; // 왼쪽 회전 (반시계)
            } else if (C == 'r') {
                Dir = (Dir + 1) % 4; // 오른쪽 회전 (시계)
            }

            if (Dir == 1) { // 위쪽으로 중력 (back에서 제거)
                while (!DQ.empty() && DQ.back() == 'b') {
                    DQ.pop_back();
                    B--;
                }
            } 
            else if (Dir == 3) { // 아래쪽으로 중력 (front에서 제거)
                while (!DQ.empty() && DQ.front() == 'b') {
                    DQ.pop_front();
                    B--;
                }
            }
        } 

        else if (S == "count") {
            cin >> C;
            cout << (C == 'b' ? B : W) << "\n";
        }
    }
}

int main() {
    FASTIO
    input();
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 전역 변수 선언
string ans; // 가장 긴 단어 저장
unordered_map<string, bool> words; // 단어 존재 여부 및 처리 여부 확인

// 단어를 검사하는 함수
void check(const string &x)
{
    for (size_t i = 0; i < x.size(); ++i)
    {
        // i번째 문자를 제거한 새로운 문자열
        string n = x.substr(0, i) + x.substr(i + 1);

        // n이 words에 존재하고 이미 처리된 단어라면
        if (words.find(n) != words.end() && words[n])
        {
            words[x] = true; // 현재 단어 x를 처리 완료로 표시
            if (x.size() > ans.size()) // 더 긴 단어 발견 시 갱신
            {
                ans = x;
            }
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string word;
    cin >> N >> word;

    // 단어 목록 입력 받기
    vector<string> inputWords(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> inputWords[i];
    }

    // 단어를 unordered_map으로 변환
    for (const string &w : inputWords)
    {
        words[w] = false; // 초기값 false
    }

    // 초기 단어 설정
    words[word] = true;
    ans = word;

    // 단어를 길이순으로 정렬
    sort(inputWords.begin(), inputWords.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    // 단어 검사
    for (const string &x : inputWords)
    {
        check(x);
    }

    // 결과 출력
    cout << ans << '\n';

    return 0;
}

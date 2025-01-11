#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0;
    cin >> n;

    vector<int> nums(n);
    for(int idx = 0; idx < n; ++idx)
    {
        cin >> nums[idx];
        sum += nums[idx];
    }

    sort(nums.begin(), nums.end());

    // 산술평균
    int mean = round(static_cast<double>(sum) / n);

    // 중앙값
    int median = nums[n / 2];

    unordered_map<int, int> freq;
    for(int n : nums)
    {
        freq[n]++;
    }

    int maxFreq = 0;
    vector<int> findMode;
    for(auto& [n, count] : freq)
    {
        if(count > maxFreq)
        {
            maxFreq = count;
            findMode = {n};
        }
        else if(count == maxFreq)
        {
            findMode.push_back(n);
        }
    }

    sort(findMode.begin(), findMode.end());

    //최빈값
    int mode = findMode.size() > 1 ? findMode[1] : findMode[0];

    // 범위 계산
    int range = nums.back() - nums.front();

    cout << mean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
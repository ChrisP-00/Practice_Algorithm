#include <iostream> 
#include <vector> 

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main()
{
    fast; 

    int n;
    cin >> n;

    vector<int> numbers(10001, 0);

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        numbers[num]++;
    }

    for(int i = 0; i < 10001; ++i)
    {
        while(numbers[i] > 0)
        {
            cout << i << '\n';
            numbers[i]--;
        }
    }

    return 0;
}
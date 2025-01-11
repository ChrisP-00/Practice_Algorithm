#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct person
{
    int age;
    string name;
    int idx;
};

int main()
{
    fast;
    int n; 
    cin >> n;

    vector<person> people(n);

    for(int idx = 0; idx < n; ++idx)
    {
        cin >> people[idx].age >> people[idx].name;
        people[idx].idx = idx;
    }

    sort(people.begin(), people.end(), [](const person &a, const person &b)
    {
        if(a.age == b.age)
        {
            return a.idx < b.idx;
        }

        return a.age < b.age;
    });

    for(auto &p : people)
    {
        cout << p.age << ' ' << p.name << '\n';
    }

    return 0;
}
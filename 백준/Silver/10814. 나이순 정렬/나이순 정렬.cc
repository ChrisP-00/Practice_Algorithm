#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct person
{
    int age;
    string name;
    int idx;
};


int main()
{
    int n; 
    cin >> n;

    vector<person> people(n);

    for(int idx = 0; idx < n; ++idx)
    {
        int a;
        string name;
        cin >> a >> name;

        people[idx] = {a, name, idx};
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
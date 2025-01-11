#include <iostream>
#include <vector>

using namespace std;

struct person
{
    int weight;
    int height;
    int rank;
    int index;
};

int main()
{
    int tc; 
    cin >> tc;

    vector<person> people(tc);

    for(int idx = 0; idx < tc; ++idx)
    {
        int w, h;
        cin >> w >> h;
        people[idx] = {w, h, 1, idx};
    }

    for(int i = 0; i < tc; ++i)
    {
        for(int j = 0; j < tc; ++j)
        {
            if(i != j && people[i].weight < people[j].weight && people[i].height < people[j].height)
            {
                people[i].rank++;
            }
        }
    }

    for(const auto &p: people)
    {
        cout << p.rank << ' ';
    }

    return 0;
}
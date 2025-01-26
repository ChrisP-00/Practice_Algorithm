#include <iostream> 
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n; 
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    while(n--)
    {
        int input;
        cin >> input;
        
        if(input != 0)
        {
            pq.push(input);
        }
        else
        {
            if(!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
            {
                cout << "0\n";
            }
        }  
    }
    
    return 0;
}
#include <iostream> 
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std; 

vector<bool> isVisited;
vector<vector<int>> g;

void dfs(int cur)
{
    cout << cur << ' ';
    isVisited[cur] = true;

    for(int node: g[cur])
    {
        if(isVisited[node])
        {
            continue;
        }
        
        dfs(node);
    }
}

void bfs(int start)
{
    queue<int> q; 
    q.push(start);
    isVisited[start] = true;
    cout << start << ' ';

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int node : g[cur])
        {
            if(isVisited[node])
            {
                continue;
            }

            isVisited[node] = true;
            q.push(node);
            cout << node << ' ';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n,  m, v;
    
    cin >> n >> m >> v;
    
    g.assign(n + 1, vector<int>());
    isVisited.assign(n + 1, false);
    
    for(int i = 1; i <= m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    for(auto& row : g)
    {
        sort(row.begin(), row.end());
    }

    dfs(v);
    cout << '\n';

    fill(isVisited.begin(), isVisited.end(), false);
    bfs(v);
    
    return 0;
}
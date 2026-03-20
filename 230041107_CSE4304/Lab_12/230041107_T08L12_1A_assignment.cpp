#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        edges[x].push_back(y);
    }

    int src, des;
    cin >> src >> des;

    queue<int> q;
    q.push(src);
    vector<int> vis(n + 1, 0);
    vis[src] = 1;

    if(src == des) 
    {
        cout << "Yes\n";
        return 0;
    }

    while (!q.empty())
    {
        for(auto &x:edges[q.front()])
        {
            if(x == des) 
            {
                cout << "Yes\n";
                return 0;
            }

            if(!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
        }
        q.pop();
    }

    cout << "No\n";
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> in_degree(n, 0);
    vector<vector<int>> edges(n);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        edges[x].emplace_back(y);
        in_degree[y]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(!in_degree[i]) q.push(i);
    }

    queue<int> ans;

    while(!q.empty())
    {
        for(auto &x:edges[q.front()])
        {
            in_degree[x]--;
            if(!in_degree[x]) q.push(x);
        }
        ans.push(q.front());
        q.pop();
    }

    if(ans.size() != n) cout << "[ ]" << endl;
    else 
    {
        while (!ans.empty())
        {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;   
    }
}
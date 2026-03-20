#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
    int v, e, q;
    cin >> v >> e >> q;

    vector<string> names(v + 1);
    map<string, int> m;

    for(int i = 1; i <= v; i++)
    {
        string s;
        cin >> s;

        m[s] = i;
        names[i] = s;
    }

    vector<vector<int>> edges(v + 1);
    vector<int> inDegree(v + 1, 0);

    for(int i = 0; i < e; i++)
    {
        string a, b;
        cin >> a >> b;

        edges[m[a]].push_back(m[b]);
        inDegree[m[b]]++;
    }

    queue<int> order;

    for(int i = 1; i <= v; i++)
    {
        if(!inDegree[i]) order.push(i);
    }

    vector<int> res;
    map<string, int> comp;

    while(!order.empty())
    {
        for(auto &x:edges[order.front()])
        {
            inDegree[x]--;
            if(!inDegree[x]) order.push(x);
        }
        res.push_back(order.front());
        order.pop();
    }

    if(res.size() != v) 
    {
        cout << "Impossible" << endl;
        while(q--)
        {
            string a, b;
            cin >> a >> b;
        }
        return 0;
    }

    for(int i = 0; i < v; i++)
    {
        cout << names[res[i]] << " ";
        comp[names[res[i]]] = i;
    }
    cout << endl;

    while(q--)
    {
        string a, b;
        cin >> a >> b;

        if(comp[b] < comp[a]) cout << "YES\n";
        else cout << "NO\n";
    }
}
#include<iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;

struct node
{
    int color;
    int d;
    int f;
    int pre;
};

map<pair<int, int>, int> mp;

void dfs_vist(vector<vector<int>> &edges, int &u, int &time, vector<node> &nodes)
{
    time += 1;
    nodes[u].d = time;
    nodes[u].color = 1;

    cout << u << " ";

    for(auto &x:edges[u])
    {
        if(nodes[x].color == 0)
        {
            mp[make_pair(u, x)] = 1;
            nodes[x].pre = u;
            dfs_vist(edges, x, time, nodes);
        }
        else if(nodes[x].color == 1)
        {
            mp[make_pair(u ,x)] = 2;
        }
        else
        {
            if(nodes[u].d < nodes[x].d)
            {
                mp[make_pair(u, x)] = 3;
            }
            else
            {
                mp[make_pair(u, x)] = 4;
            }
        }
    }

    nodes[u].color = 2;
    time += 1;
    nodes[u].f = time;
}

void dfs(vector<vector<int>> &edges, int &v, vector<node> &nodes)
{
    for(int i = 1; i <= v; i++)
    {
        nodes[i].color = 0;
        nodes[i].pre = 0;
    }
    int time = 0;

    cout << "DFS order: ";

    for(int i = 1; i <= v; i++)
    {
        if(nodes[i].color == 0)
        {
            dfs_vist(edges, i, time, nodes);
        }
    }
    cout << endl;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges(v + 1);
    vector<pair<int, int>> vp;

    for(int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        vp.push_back(make_pair(a, b));
    }

    cout << "Adjacency list:" << endl;
    for(int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for(auto &x:edges[i]) cout << x << " ";
        cout << endl;
    }

    vector<node> nodes(v + 1);
    dfs(edges, v, nodes);

    cout << "Timestamps of Vertex(discovery/finishing):" << endl;
    for(int i = 1; i <= v; i++)
    {
        cout << i << "(" << nodes[i].d << "/" << nodes[i].f << ")" << endl;
    }

    cout << "Edge classification:" << endl;

    for(auto &x:vp)
    {
        cout << x.first << " " << x.second << ": ";
        if(mp[x] == 1) cout << "Tree Edge" << endl;
        else if(mp[x] == 2) cout << "Back Edge" << endl;
        else if(mp[x] == 3) cout << "Forward Edge" << endl;
        else if(mp[x] == 4) cout << "Cross Edge" << endl;
    }
}

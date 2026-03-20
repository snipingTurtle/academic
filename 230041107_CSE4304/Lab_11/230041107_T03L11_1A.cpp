#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
    int color;
    int d;
    int pre;
};

void bfs(vector<vector<int>> &edges, int &v, int &s, vector<node> &nodes)
{
    for(int i = 1; i <= v; i++)
    {
        if(i != s)
        {
            nodes[i].color = 0;
            nodes[i].d = 1e9;
            nodes[i].pre = 0;
        }
    }

    nodes[s].color = 1;
    nodes[s].d = 0;
    nodes[s].pre = 0;

    queue<int> q;
    q.push(s);

    cout << "BFS order: ";

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(auto &x:edges[u])
        {
            if(nodes[x].color == 0)
            {
                nodes[x].color = 1;
                nodes[x].d = nodes[u].d + 1;
                nodes[x].pre = u;

                q.push(x);
            }
        }

        nodes[u].color = 2;
    }
    cout << endl;
}

void print_path(int &u, vector<node> &nodes)
{
    if(nodes[u].pre == 0)
    {
        cout << u;
        return;
    }

    print_path(nodes[u].pre, nodes);
    cout << "->";
    cout << u;
}

int main()
{
    int v, e, s;
    cin >> v >> e >> s;

    vector<vector<int>> edges(v + 1);

    for(int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << "Adjacency list:" << endl;
    for(int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for(auto &x:edges[i]) cout << x << " ";
        cout << endl;
    }
    cout << endl;

    vector<node> nodes(v + 1);

    bfs(edges, v, s, nodes);

    cout << "Distance from source: " << endl;
    for(int i = 1; i <= v; i++)
    {
        cout << i << "(" << nodes[i].d << ") ";
    }
    cout << endl;

    cout << "Paths from source:" << endl;
    for(int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        print_path(i, nodes);
        cout << endl;
    }
    cout << endl;

    cout << "Edges of BFS tree:" << endl;
    for(int i = 1; i <= v; i++)
    {
        if(nodes[i].pre)
        {
            cout << nodes[i].pre << " " << i << endl;
        }
    }
}

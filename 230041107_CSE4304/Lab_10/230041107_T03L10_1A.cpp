#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> list_edge(v + 1);
    vector<vector<int>> mat_edge(v + 1, vector<int>(v + 1, 0));

    for(int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        list_edge[x].emplace_back(y);
        list_edge[y].emplace_back(x);

        mat_edge[x][y]++;
        mat_edge[y][x]++;
    }

    cout << "Adjacency List:" << endl;
    for(int i = 1; i <= v; i++)
    {
        cout << i << ": ";

        for(auto &x:list_edge[i]) cout << x << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Adjacency Matrix:" << endl;
    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            cout << mat_edge[i][j] << " ";
        }
        cout << endl;
    }
}
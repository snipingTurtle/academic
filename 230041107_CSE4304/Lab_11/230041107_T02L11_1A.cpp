#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges(v + 1);

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int num = edges[1].size();

    for(int i = 2; i <= v; i++)
    {
        if(edges[i].size() != num)
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}

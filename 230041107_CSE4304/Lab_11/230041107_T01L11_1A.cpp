#include<iostream>

using namespace std;

int find(const int &u, int parent[])
{
    if(parent[u] == u)
    {
        return parent[u];
    }
    else
    {
        return parent[u] = find(parent[u], parent);
    }
}

void set_union(int i, int j, int parent[], int rank[], int size[])
{
    int ri = find(i, parent);
    int rj = find(j, parent);

    if(ri != rj)
    {
        if(rank[ri] <= rank[rj])
        {
            parent[ri] = rj;
            size[rj] += size[ri];
        }
        else
        {
            parent[rj] = ri;
            size[ri] += size[rj];
        }

        if(rank[ri] == rank[rj])
        {
            rank[rj]++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int parent[n + 1];
    for(int i = 1; i <= n; i++) parent[i] = i;

    int size[n + 1];
    for(int i = 1; i <= n; i++) size[i] = 1;

    int rank[n + 1];
    for(int i = 1; i <= n; i++) rank[i] = 1;

    int sz = 1;
    int num = n;

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        int p1 = find(a, parent);
        int p2 = find(b, parent);

        if(p1 != p2)
        {
            set_union(p1, p2, parent, rank, size);
            num--;
            sz = max(sz, size[parent[p1]]);
        }

        cout << num << " " << sz << endl;
    }
}

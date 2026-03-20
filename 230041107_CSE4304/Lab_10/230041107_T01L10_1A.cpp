#include<iostream>
#include<vector>

using namespace std;

class DSU
{
private:
    int n;
    vector<int> parent;

public:
    void init(const int &size)
    {
        n = size;
        for(int i = 0; i < n; i++) parent.emplace_back(i);
    } 

    int find(const int &u)
    {
        if(parent[u] == u) return u;
        else return find(parent[u]);
    }

    void set_union(int i, int j)
    {
        int ri = find(i);
        int rj = find(j);

        if(ri != rj)
        {
            parent[rj] = ri;
        }
    }

    void print_state() const
    {
        for(int i = 0; i < n; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    DSU d;

    int choice;

    while(cin >> choice)
    {
        if(choice == 1)
        {
            d.init(n);
        }
        else if(choice == 2)
        {
            int x;
            cin >> x;

            cout << d.find(x) << endl;
        }
        else if(choice == 3)
        {
            int i, j;
            cin >> i >> j;

            d.set_union(i, j);
        }

        d.print_state();
    }
}
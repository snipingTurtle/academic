#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class DSU
{
private:
    int n;
    vector<int> parent;
    vector<int> rank;
    queue<int> func_calls;

public:
    void init(const int &size)
    {
        n = size;
        for(int i = 0; i < n; i++) 
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
        }
    } 

    int find(const int &u)
    {
        func_calls.push(u);
        if(parent[u] == u)
        {
            return parent[u];
        }
        else 
        {
            return parent[u] = find(parent[u]);
        }
    }

    void set_union(int i, int j)
    {
        int ri = find(i);
        int rj = find(j);

        if(ri != rj)
        {
            if(rank[ri] <= rank[rj])
            {
                parent[ri] = rj;
            }
            else parent[rj] = ri;

            if(rank[ri] == rank[rj])
            {
                rank[rj]++;
            }
        }
    }

    void print_state() const
    {
        for(int i = 0; i < n; i++)
        {
            cout << parent[i] << "(" << rank[i] << ") ";
        }
        cout << endl;
    }

    void print_func_calls()
    {
        while(!func_calls.empty())
        {
            cout << "f(" << func_calls.front() << ") ";
            func_calls.pop();
        }
        cout << endl;
    }

    void clear_stack()
    {
        while(!func_calls.empty()) func_calls.pop();
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
            d.print_state();
        }
        else if(choice == 2)
        {
            d.clear_stack();

            int x;
            cin >> x;

            cout << d.find(x) << endl;
            d.print_func_calls();
        }
        else if(choice == 3)
        {
            int i, j;
            cin >> i >> j;

            d.set_union(i, j);
            d.print_state();
        }
        else if(choice == 4) d.print_state();
    }
}
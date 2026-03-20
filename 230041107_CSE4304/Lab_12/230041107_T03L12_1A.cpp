#include<iostream>
#include<vector>

using namespace std;

void construct_BIT(vector<int> &a, vector<int> &tree, const int &n)
{
    for(int i = 1; i <= n; i++)
    {
        int j = i + (i & -i);
        if(j <= n) 
        {
            tree[j] += tree[i];
        }
    }
}

int pref_sum(vector<int> &tree,int id)
{
    int sm = 0;

    while(id > 0)
    {
        sm += tree[id];
        int j = id & -id;
        id -= j;
    }

    return sm;
}

int query(vector<int> &tree, int l, int r)
{
    return pref_sum(tree, r) - pref_sum(tree, l - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    vector<int> tree(n + 1);
    for(int i = 1; i <= n; i++) tree[i] = v[i];
    construct_BIT(v, tree, n);

    cout << "Ranges to be stored in the Fenwick Table:" << endl;
    for(int i = 1; i <= n; i++)
    {
        int window = i & -i;
        cout << i << ":(" << (i - window + 1) << "," << i << ") ";
    }
    cout << endl;

    cout << "Status of Fenwick Tree (idx: value):" << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << i << ":" << tree[i] << " ";
    }
    cout << endl;

    int q;
    cin >> q;

    for(int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << "Query-" << i << ": Sum=" << query(tree, l, r) << " [Tree idx: sum(";
        while(r > 0)
        {
            cout << r;
            r -= (r & -r);
            if(r != 0) cout << ",";
        }
        cout << ") - sum(";
        while(l > 0)
        {
            cout << l;
            l -= (l & -l);
            if(l != 0) cout << ",";
        }
        cout << ")]" << endl;
    }
}
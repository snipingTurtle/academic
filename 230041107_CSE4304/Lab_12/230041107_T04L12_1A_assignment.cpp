#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>
class SparseTable
{
private:
    vector<T> v;
    vector<vector<T>> table;
    int n;

    void init()
    {
        for (int i = 0; i < n; i++)
            table[i][0] = v[i];

        for (int j = 1; j <= (int)log2(n); j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                table[i][j] = func(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T func(const T &a, const T &b) const
    {
        return a | b;
    }

public:
    SparseTable(const vector<T> &a) : v(a), n(a.size())
    {
        table.resize(n, vector<T>((int)log2(n) + 1));
        init();
    }

    T query(int l, int r)
    {
        int window = r - l + 1;
        int j = log2(window);

        T res = func(table[l][j], table[r - (1 << j) + 1][j]);
        return res;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &x:v) cin >> x;

    SparseTable<int> st(v);

    int q;
    cin >> q;

    while(q--)
    {
        int l, r, i;
        cin >> l >> r >> i;

        l--;
        r--;
        i--;

        if(st.query(l, r) == v[i]) cout << "YES\n";
        else cout << "NO\n";
        // cout << st.query(l, r) << " " << v[i - 1] << endl;
    }
}
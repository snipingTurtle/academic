#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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
        return __gcd(a, b);
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

    void printTable()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; (i + (1 << j) - 1) < n; j++)
            {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v[i] = x;
    }

    SparseTable<int> st(v);

    cout << "Ranges to be stored in Sparse Table:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (i + (1 << j) - 1) < n; j++)
        {
            cout << "(" << i << "," << (i + (1 << j) - 1) << ") ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Status of Sparse Table:" << endl;
    st.printTable();

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;

        int window = r - l + 1;
        int j = log2(window);

        cout << "Query-" << i << ": GCD=" << st.query(l, r) << " gcd([" << l << "," << (l + (1 << j) - 1) << "],[" << (r - (1 << j) + 1) << "," << r << "])" << endl;
    }
}
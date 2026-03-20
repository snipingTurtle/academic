#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> table(n, vector<int>((int)log2(n) + 1));

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        table[i][0] = x;
    }
    
    for(int j = 1; j <= (int)log2(n); j++)
    {
        for(int i = 0; i + (1<<j) - 1 < n; i++)
        {
            table[i][j] = min(table[i][j - 1], table[i + (1<<(j - 1))][j - 1]);
        }
    }
    
    cout << "Ranges to be stored in Sparse Table:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; (i + (1 << j) - 1) < n; j++)
        {
            cout << "(" << i << "," << (i + (1<<j) - 1) << ") ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Status of Sparse Table:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; (i + (1 << j) - 1) < n; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int q;
    cin >> q;

    for(int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;

        int window = r - l + 1;
        int j = log2(window);

        int res = min(table[l][j], table[r - (1 << j) + 1][j]);

        cout << "Query-" << i << ": Min=" << res << " min([" << l << "," << (l + (1 << j) - 1) << "],[" << (r - (1 << j) + 1) << "," << r << "])" << endl;
    }
}
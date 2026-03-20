#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<int> opref(n + 1, 0);
    vector<int> zpref(n + 1, 0);

    for(auto &x:v) cin >> x;

    for(int i = 0; i < n; i++)
    {
        if(v[i] == 0)
        {
            zpref[i + 1] = zpref[i] + 1;
            opref[i + 1] = opref[i];
        }
        else
        {
            zpref[i + 1] = zpref[i];
            opref[i + 1] = opref[i] + 1;
        }
    }

    while(q--)
    {
        int l ,r;
        cin >> l >> r;

        int ze = zpref[r] - zpref[l - 1];
        int on = opref[r] - opref[l - 1];

        int mx = max(ze, on);
        int mn = min(ze, on);

        int dif = r - l;
        if(dif % 2)
        {
            int res = mx - ((mx + mn) / 2);
            cout << res << endl;
        }
        else cout << -1 << endl;
    }
}
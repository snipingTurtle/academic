#include<iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int q;
    cin >> q;

    int pref[26][n + 1];
    for(int i = 0; i < 26; i++) pref[i][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int comp = s[i - 1] - 'a';
        for(int j = 0; j < 26; j++)
        {
            if(comp == j)
            {
                pref[j][i] = pref[j][i - 1] + 1;
            }
            else pref[j][i] = pref[j][i - 1];
        }
    }

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        int mx = 0;
        char ans = 'a';

        for(int i = 0; i < 26; i++)
        {
            int k = pref[i][r] - pref[i][l - 1];
            if(k > mx)
            {
                mx = k;
                ans = 'a' + i;
            }
        }

        cout << ans << ":" << mx << endl;
    }
}
#include<iostream>

using namespace std;

int main()
{
    int len, n;
    cin>>len>>n;

    string ar[n];

    for(int i = 0; i < n; i++) cin>>ar[i];

    int ars[n];
    int mx = 1e9;
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        int t, g, c;
        t = g = c = 0;
        for(int j = 0; j < len; j++)
        {
            if(ar[i][j] == 'A')
            {
                x += t;
                x += g;
                x += c;
            }
            else if(ar[i][j] == 'C')
            {
                x += t;
                x += g;
                c++;
            }
            else if(ar[i][j] == 'G')
            {
                x += t;
                g++;
            }
            else t++;
        }
        ars[i] = x;
        if(x < mx) mx = x;
    }

    int cnt = 0;

    while(1)
    {
        if(cnt == n) break;
        else if(mx > 0)
        {
            int temp = 1e9;
            for(int i = 0; i < n; i++)
            {
                if(ars[i] == mx)
                {
                    cout<<ar[i]<<" "<<ars[i]<<"\n";
                    cnt++;
                }
                else if((ars[i] > mx) && (ars[i] < temp)) temp = ars[i];
            }
            mx = temp;
        }
    }
}

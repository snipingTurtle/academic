#include<iostream>

using namespace std;

const int MAXN = 1e4 + 1;

int main()
{
    int arr[MAXN];

    int n = 1;
    while(1)
    {
        int x;
        cin>>x;

        if(!x) break;
        arr[n] = x;
        n++;
    }

    int des;
    cin>>des;

    n--;

    int res = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if((arr[i] + arr[j]) == des)
            {
                res++;
            }
        }
    }

    if(res == 0) cout<<"No pair found!\n";
    else if(res == 1) cout<<"1 Pair:\n";
    else cout<<res<<" Pairs:\n";

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if((arr[i] + arr[j]) == des)
            {
                cout<<"(worker-"<<i<<", worker-"<<j<<")\n";
            }
        }
    }
}

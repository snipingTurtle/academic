#include<iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int main()
{
    int freq[MAXN] = {0};

    while(1)
    {
        int x;
        cin>>x;

        if(x == -1)
            break;

        freq[x]++;
    }

    while(1)
    {
        int x;
        cin>>x;

        if(x == -1)
            break;

        if(freq[x])
        {
            freq[x]--;
            cout<<x<<" ";
        }
    }

    cout<<endl;
}
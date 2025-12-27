#include<iostream>

using namespace std;

int main()
{
    int n, r;
    cin>>n>>r;

    int ar[n];
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>ar[i];
        if(ar[i] > mx) mx = ar[i];
    }

    int arr[mx + 1] = {0};

    for(int i = 0; i < n; i++)
    {
        arr[ar[i]]++;
    }

    int pre[mx + 1] = {0};
    int sm[mx + 1] = {0};
    for(int i = 1; i <= mx; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
        if(arr[i] > 0) sm[i] = sm[i - 1] + i;
        else sm[i] = sm[i - 1];
    }

    while(r--)
    {
        int x;
        cin>>x;

        if(x <= mx)
        {
            cout<<pre[x]<<" "<<sm[x]<<"\n";
        }
        else
        {
            cout<<pre[mx]<<" "<<sm[mx]<<"\n";
        }
    }
}

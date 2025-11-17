#include<iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int main()
{
    int n = 0;
    int arr[MAXN];
    
    while(1)
    {
        int x;
        cin>>x;

        if(x == -1) break;
        arr[n] = x;
        n++;
    }

    double res[n];

    for(int i = 0; i < n; i++)
    {
        double x;
        cin>>x;

        res[arr[i] - 1] = x;
    }

    for(int j = 0; j < n; j++)
    {
        cout<<res[j]<<" ";
    }

    cout<<"\n";
}
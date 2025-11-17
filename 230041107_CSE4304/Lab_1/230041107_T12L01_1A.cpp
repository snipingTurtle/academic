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

    int mx[n];

    mx[0] = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(i >= 2) mx[i] = arr[i] + mx[i - 2];
        else mx[i] = arr[i];
        mx[i] = max(mx[i - 1], mx[i]);
    }

    cout<<mx[n - 1]<<endl;
}
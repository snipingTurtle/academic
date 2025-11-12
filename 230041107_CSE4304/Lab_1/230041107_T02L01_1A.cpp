#include<iostream>

using namespace std;

int iter_fact(int n)
{
    int fact[n + 1];
    fact[0] = 1;

    for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;

    return fact[n];
}

int rec_fact(int n)
{
    if(!n) return 1;
    return (n * rec_fact(n - 1));
}

int main()
{
    int n;
    cin>>n;

    cout<<iter_fact(n)<<" (using iteration)"<<endl;
    cout<<rec_fact(n)<<" (using recursion)"<<endl;
}
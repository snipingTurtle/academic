#include<iostream>

using namespace std;

int rec_fib(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    return rec_fib(n-1) + rec_fib(n-2);
}

int iter_fib(int n)
{
    n--;
    if(n == 0) return 0;
    if(n == 1) return 1;

    int a = 0;
    int b = 1;

    for(int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    cout << "Recursive: " << rec_fib(n) << endl;
    cout << "Iterative: " << iter_fib(n) << endl;
}
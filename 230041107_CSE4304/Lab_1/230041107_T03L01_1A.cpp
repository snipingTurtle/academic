#include<iostream> 

using namespace std;

const int MAXN = 1e6 + 1;

int iter_bin_search(int x, int array[], int n);
int rec_bin_search(int x, int array[], int a, int b);

int main()
{
    int array[MAXN];

    int i = 0;

    while(1)
    {
        int x;
        cin>>x;
        if(x < 0) break;
        array[i] = x;
        i++;
    }

    int x;
    cin>>x;

    cout<<iter_bin_search(x, array, i)<<" (using iteration)"<<endl;
    cout<<rec_bin_search(x, array, 0, i - 1)<<" (using recursion)"<<endl;
}

int iter_bin_search(int x, int array[], int n)
{
    int a = 0;
    int b = n - 1;

    while(a <= b)
    {
        int md = (a + b) / 2;

        if(array[md] == x) return md;
        else if(array[md] >= x) b = md - 1;
        else a = md + 1;
    }

    return -1;
}

int rec_bin_search(int x, int array[], int a, int b)
{
    if(a > b) return -1;
    int md = (a + b) / 2;
    if(array[md] == x) return md;
    else if(array[md] > x) return rec_bin_search(x, array, a, md - 1);
    else return rec_bin_search(x, array, md + 1, b);
}
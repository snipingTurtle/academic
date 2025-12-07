#include<iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int ar[MAXN];

void min_heapify(int parent, int n)
{
    int L_child = 2 * parent;
    int R_child = (2 * parent) + 1;

    int smallest;

    if((L_child <= n) && (ar[L_child] < ar[parent]))
    {
        smallest = L_child;
    }
    else smallest = parent;

    if((R_child <= n) && (ar[R_child] < ar[smallest]))
    {
        smallest = R_child;
    }

    if(smallest != parent)
    {
        int temp = ar[smallest];
        ar[smallest] = ar[parent];
        ar[parent] = temp;

        min_heapify(smallest, n);
    }
}

void build_min_heap(int n)
{
    for(int i = n / 2; i > 0; i--)
    {
        min_heapify(i, n);
    }
}

void heap_sort(int n)
{
    int sz = n;
    for(int i = 1; i < n; i++)
    {
        int temp = ar[1];
        ar[1] = ar[sz];
        ar[sz] = temp;

        sz--;
        min_heapify(1, sz);
    }
}

int main()
{
    int n = 1;

    while(1)
    {
        int x;
        cin >> x;

        if(x == -1) break;
        ar[n] = x;
        n++;
    }
    n--;

    build_min_heap(n);

    cout << "Min Heap: ";
    for(int i = 1; i <= n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;

    heap_sort(n);

    cout << "Sorted: ";

    for(int i = n; i > 0; i--) cout << ar[i] << " ";
    cout << endl;
}
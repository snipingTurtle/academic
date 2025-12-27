#include<iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int ar[MAXN];

void max_heapify(int parent, int n)
{
    int L_child = 2 * parent;
    int R_child = (2 * parent) + 1;

    int largest;

    if((L_child <= n) && (ar[L_child] > ar[parent]))
    {
        largest = L_child;
    }
    else largest = parent;

    if((R_child <= n) && (ar[R_child] > ar[largest]))
    {
        largest = R_child;
    }

    if(largest != parent)
    {
        int temp = ar[largest];
        ar[largest] = ar[parent];
        ar[parent] = temp;

        max_heapify(largest, n);
    }
}

void build_max_heap(int n)
{
    for(int i = n / 2; i > 0; i--)
    {
        max_heapify(i, n);
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
        max_heapify(1, sz);
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

    build_max_heap(n);

    cout << "Max Heap: ";
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

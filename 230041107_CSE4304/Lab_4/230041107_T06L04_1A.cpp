#include<iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int n = 1;

void max_heapify(int heap[], int parent);
void build_max_heap(int heap[]);
int Heap_Maximum(int heap[]);
int Heap_extract_max(int heap[]);
void Max_heap_insert(int value, int heap[]);
void Heap_decrease_key(int i, int k, int heap[]);
void Heap_increase_key(int i, int k, int heap[]);
void reverse_heapify(int n, int heap[]);

int main()
{
    int heap[MAXN];

    while(1)
    {
        int x;
        cin >> x;

        if(x == -1) break;

        heap[n] = x;
        n++;
    }
    n--;

    build_max_heap(heap);

    cout << "Max Heap: ";
    for(int i = 1; i <= n; i++) cout << heap[i] << " ";
    cout << endl;


    int id;
    while(cin >> id)
    {
        if(id == 1)
        {
            int res = Heap_Maximum(heap);
            if(res < 0) cout << "Underflow" << endl;
            else cout << res << endl;
        }
        else if(id == 2)
        {
            int res = Heap_extract_max(heap);
            if(res >= 0) cout << res << endl;
            else cout << "Underflow" << endl;
        }
        else if(id == 3)
        {
            int x;
            cin >> x;

            Max_heap_insert(x, heap);
        }
        else if(id == 4)
        {
            int pos, val;
            cin >> pos >> val;

            Heap_decrease_key(pos, val, heap);
        }
        else if(id == 5)
        {
            int pos, val;
            cin >> pos >> val;

            Heap_increase_key(pos, val, heap);
        }
        else break;

        for(int i = 1; i <= n; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
}

void max_heapify(int heap[], int parent)
{
    int L_child = 2 * parent;
    int R_child = (2 * parent) + 1;

    int largest;

    if((L_child <= n) && (heap[L_child] > heap[parent]))
    {
        largest = L_child;
    }
    else largest = parent;

    if((R_child <= n) && (heap[R_child] > heap[largest]))
    {
        largest = R_child;
    }

    if(largest != parent)
    {
        int temp = heap[largest];
        heap[largest] = heap[parent];
        heap[parent] = temp;

        max_heapify(heap, largest);
    }
}

void build_max_heap(int heap[])
{
    for(int i = n / 2; i > 0; i--)
    {
        max_heapify(heap, i);
    }
}

int Heap_Maximum(int heap[])
{
    if(n < 1) return -1;
    return heap[1];
}

int Heap_extract_max(int heap[])
{
    if(n < 1) return -1;
    int res = heap[1];

    heap[1] = heap[n];
    n--;

    if(n > 0) max_heapify(heap, 1);

    return res;
}

void Max_heap_insert(int value, int heap[])
{
    n++;
    heap[n] = value;

    reverse_heapify(n, heap);
}

void Heap_decrease_key(int i, int k, int heap[])
{
    if(i > n) return;
    heap[i] -= k;

    max_heapify(heap, i);
}

void Heap_increase_key(int i, int k, int heap[])
{
    if(i > n) return;
    heap[i] += k;

    reverse_heapify(i, heap);
}

void reverse_heapify(int n, int heap[])
{
    if(n <= 1) return;
    int parent = n / 2;

    if(heap[n] > heap[parent])
    {
        int temp = heap[parent];
        heap[parent] = heap[n];
        heap[n] = temp;

        reverse_heapify(parent, heap);
    }
    else return;
}
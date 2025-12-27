#include<iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int n = 1;

void min_heapify(int heap[], int parent);
void build_min_heap(int heap[]);
int Heap_Minimim(int heap[]);
int Heap_extract_min(int heap[]);
void Min_heap_insert(int value, int heap[]);
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

    build_min_heap(heap);

    cout << "Min Heap: ";
    for(int i = 1; i <= n; i++) cout << heap[i] << " ";
    cout << endl;


    int id;
    while(cin >> id)
    {
        if(id == 1)
        {
            int res = Heap_Minimim(heap);
            if(res < 0) cout << "Underflow" << endl;
            else cout << res << endl;
        }
        else if(id == 2)
        {
            int res = Heap_extract_min(heap);
            if(res >= 0) cout << res << endl;
            else cout << "Underflow" << endl;
        }
        else if(id == 3)
        {
            int x;
            cin >> x;

            Min_heap_insert(x, heap);
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

void min_heapify(int heap[], int parent)
{
    int L_child = 2 * parent;
    int R_child = (2 * parent) + 1;

    int smallest;

    if((L_child <= n) && (heap[L_child] < heap[parent]))
    {
        smallest = L_child;
    }
    else smallest = parent;

    if((R_child <= n) && (heap[R_child] < heap[smallest]))
    {
        smallest = R_child;
    }

    if(smallest != parent)
    {
        int temp = heap[smallest];
        heap[smallest] = heap[parent];
        heap[parent] = temp;

        min_heapify(heap, smallest);
    }
}

void build_min_heap(int heap[])
{
    for(int i = n / 2; i > 0; i--)
    {
        min_heapify(heap, i);
    }
}

int Heap_Minimim(int heap[])
{
    if(n < 1) return -1;
    return heap[1];
}

int Heap_extract_min(int heap[])
{
    if(n < 1) return -1;
    int res = heap[1];

    heap[1] = heap[n];
    n--;

    if(n > 0) min_heapify(heap, 1);

    return res;
}

void Min_heap_insert(int value, int heap[])
{
    n++;
    heap[n] = value;

    reverse_heapify(n, heap);
}

void Heap_decrease_key(int i, int k, int heap[])
{
    if(i > n) return;
    heap[i] -= k;

    reverse_heapify(i, heap);
}

void Heap_increase_key(int i, int k, int heap[])
{
    if(i > n) return;
    heap[i] += k;

    min_heapify(heap, i);
}

void reverse_heapify(int n, int heap[])
{
    if(n <= 1) return;
    int parent = n / 2;

    if(heap[n] < heap[parent])
    {
        int temp = heap[parent];
        heap[parent] = heap[n];
        heap[n] = temp;

        reverse_heapify(parent, heap);
    }
    else return;
}

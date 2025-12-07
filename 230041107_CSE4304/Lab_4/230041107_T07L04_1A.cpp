#include<iostream>

using namespace std;

void heapify(int heap[], int parent, int sz)
{
    int lchild = parent * 2;
    int rchild = (parent * 2) + 1;

    int smallest;

    if((lchild <= sz) && (heap[lchild] < heap[parent]))
    {
        smallest = lchild;
    }
    else smallest = parent;

    if((rchild <= sz) && (heap[rchild] < heap[smallest]))
    {
        smallest = rchild;
    }

    if(smallest != parent)
    {
        int temp = heap[smallest];
        heap[smallest] = heap[parent];
        heap[parent] = temp;

        heapify(heap, smallest, sz);
    }
}

void reverse_heapify(int heap[], int pos)
{
    if(pos <= 1) return;
    int parent = pos / 2;

    if(heap[pos] < heap[parent])
    {
        int temp = heap[pos];
        heap[pos] = heap[parent];
        heap[parent] = temp;

        reverse_heapify(heap, parent);
    }
}

void heap_push(int heap[], int val, int &pos)
{
    heap[pos] = val;
    reverse_heapify(heap, pos);
    pos++;
}

void heap_pop(int heap[], int &sz)
{
    int temp = heap[1];
    heap[1] = heap[sz - 1];
    heap[sz - 1] = temp;

    sz--;

    heapify(heap, 1, sz - 1);
}

int main()
{
    int heap[5];

    int n;
    cin >> n;

    int pos = 1;

    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        heap_push(heap, x, pos);

        if(i < 2)
        {
            cout << "-1\n";
        }
        else
        {
            if(i > 2) heap_pop(heap, pos);
            int res = heap[1] * heap[2] * heap[3];

            cout << res << endl;
        }
    }
}
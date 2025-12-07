#include<iostream>
#include<string>

using namespace std;

struct Wizard
{
    string first_name, last_name;
    int age;
    string house;
};

const int MAXN = 1e3 + 1;

int n = 0;

void max_heapify(Wizard heap[], int parent);
Wizard Heap_extract_max(Wizard heap[]);
void Max_heap_insert(Wizard value, Wizard heap[]);
void reverse_heapify(int n, Wizard heap[]);

int main()
{
    Wizard heap[MAXN];

    char c;
    while(1)
    {
        cin >> c;
        if(c == 'X') break;
        else if(c == 'I')
        {
            Wizard wiz;

            cin >> wiz.first_name >> wiz.last_name >> wiz.age >> wiz.house;

            Max_heap_insert(wiz, heap);
        }
        else if(c == 'S')
        {
            Wizard wiz = Heap_extract_max(heap);
            cout << "Name: " << wiz.first_name << " " << wiz.last_name << ", Age: " << wiz.age << ", House: " << wiz.house << endl;
        }
    }
}
void max_heapify(Wizard heap[], int parent)
{
    int L_child = 2 * parent;
    int R_child = (2 * parent) + 1;

    int lar;

    if((L_child <= n) && (heap[L_child].age > heap[parent].age))
    {
        lar = L_child;
    }
    else lar = parent;

    if((R_child <= n) && (heap[R_child].age > heap[lar].age))
    {
        lar = R_child;
    }

    if(lar != parent)
    {
        Wizard temp = heap[lar];
        heap[lar] = heap[parent];
        heap[parent] = temp;

        max_heapify(heap, lar);
    }
}

Wizard Heap_extract_max(Wizard heap[])
{
    if(n < 1)
    {
        Wizard wiz;
        wiz.age = -1;
        return wiz;
    }
    Wizard res = heap[1];

    heap[1] = heap[n];
    n--;

    if(n > 0) max_heapify(heap, 1);

    return res;
}

void Max_heap_insert(Wizard value, Wizard heap[])
{
    n++;
    heap[n] = value;

    reverse_heapify(n, heap);
}

void reverse_heapify(int n, Wizard heap[])
{
    if(n <= 1) return;
    int parent = n / 2;

    if(heap[n].age > heap[parent].age)
    {
        Wizard temp = heap[parent];
        heap[parent] = heap[n];
        heap[n] = temp;

        reverse_heapify(parent, heap);
    }
    else return;
}
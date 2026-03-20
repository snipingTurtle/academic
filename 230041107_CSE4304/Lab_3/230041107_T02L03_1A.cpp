#include <iostream>

using namespace std;

const int MAXN = 1e6 + 1;

int front = 0;
int rear = 1;
int cnt = 0;

int deque[MAXN];

void print_queue();
void push_front(int key);
void push_back(int key);
int pop_front();
int pop_back();
int size();

int main()
{
    int id;
    while (1)
    {
        cin >> id;
        if (id == 6)
            break;
        else if (id == 1)
        {
            int x;
            cin >> x;

            push_front(x);
        }
        else if (id == 2)
        {
            int x;
            cin >> x;

            push_back(x);
        }
        else if (id == 3)
        {
            pop_front();
        }
        else if (id == 4)
        {
            pop_back();
        }
        else if (id == 5)
        {
            cout << size() << endl;
        }
    }
}

void print_queue()
{
    for (int i = 0; i < cnt; i++)
    {
        int pos = (i + front + 1) % (MAXN - 1);
        cout << deque[pos] << " ";
    }
    cout << endl;
}

void push_front(int key)
{
    if (cnt == (MAXN - 1))
        cout << "Overflow" << endl;
    else
    {
        deque[front] = key;
        front--;
        front = (front + MAXN - 1) % (MAXN - 1);
        cnt++;
        print_queue();
    }
}

void push_back(int key)
{
    if (cnt == (MAXN - 1))
        cout << "Overflow" << endl;
    else
    {
        deque[rear] = key;
        rear = (rear + 1) % (MAXN - 1);
        cnt++;
        print_queue();
    }
}

int pop_front()
{
    if (cnt == 0)
        cout << "Underflow" << endl;
    else
    {
        int res = deque[front];
        front = (front + 1) % (MAXN - 1);
        cnt--;
        print_queue();
        return res;
    }
}

int pop_back()
{
    if (cnt == 0)
        cout << "Underflow" << endl;
    else
    {
        int res = deque[rear];
        rear--;
        rear = (rear + MAXN - 1) % (MAXN - 1);
        cnt--;
        print_queue();

        return res;
    }
}

int size()
{
    return cnt;
}

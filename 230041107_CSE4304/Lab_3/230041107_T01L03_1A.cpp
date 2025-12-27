#include<iostream>

using namespace std;

void print_queue(int queue[], int front, int cnt, int Maxq);
void EnQueue(int queue[], int &front, int &rear, int &cnt, int value, int Maxq);
void DeQueue(int queue[], int &front, int &cnt, int Maxq);
int isEmpty(int cnt);
int isFull(int cnt, int Maxq);
int q_size(int cnt);
int q_front(int queue[], int front);

int main()
{
    int n;
    cin >> n;

    int queue[n];

    int front = 0;
    int rear = 0;
    int cnt = 0;

    while(1)
    {
        int id;
        cin >> id;

        if(id == -1)
        {
            cout << "Exit" << endl;
            break;
        }
        else if(id == 1)
        {
            int x;
            cin >> x;

            EnQueue(queue, front, rear, cnt, x, n);
        }
        else if(id == 2)
        {
            DeQueue(queue, front, cnt, n);
        }
        else if(id == 3)
        {
            if(isEmpty(cnt)) cout << "isEmpty: True" << endl;
            else cout << "isEmpty: False" << endl;
        }
        else if(id == 4)
        {
            if(isFull(cnt, n)) cout << "isFull: True" << endl;
            else cout << "isFull: False" << endl;
        }
        else if(id == 5)
        {
            cout << "Size: " << q_size(cnt) << endl;
        }
        else if(id == 6)
        {
            cout << "Front: " << q_front(queue, front) << endl;
        }
    }
}


void print_queue(int queue[], int front, int cnt, int Maxq)
{
    for(int i = 0; i < cnt; i++)
    {
        int x = (front + i) % Maxq;
        cout << queue[x] << " ";
    }
    cout << endl;
}


void EnQueue(int queue[], int &front, int &rear, int &cnt, int value, int Maxq)
{
    if(cnt == Maxq)
    {
        cout << "EnQueue: Overflow" << endl;
        return;
    }
    cnt++;
    queue[rear] = value;
    rear = (rear + 1) % Maxq;

    cout << "EnQueue: ";
    print_queue(queue, front, cnt, Maxq);
}


void DeQueue(int queue[], int &front, int &cnt, int Maxq)
{
    if(cnt == 0)
    {
        cout << "DeQueue: Underflow" << endl;;
        return;
    }

    cnt--;
    front = (front + 1) % Maxq;

    cout << "DeQueue: ";
    print_queue(queue, front, cnt, Maxq);
}


int isEmpty(int cnt)
{
    if(cnt == 0) return 1;
    else return 0;
}


int isFull(int cnt, int Maxq)
{
    if(cnt == Maxq) return 1;
    else return 0;
}


int q_size(int cnt)
{
    return cnt;
}


int q_front(int queue[], int front)
{
    return queue[front];
}

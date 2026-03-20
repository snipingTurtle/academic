#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Queue
{
    Node *head = NULL;
    Node *tail = NULL;
    int max_size;
    int curr_size = 0;
};

void enqueue(Queue *q, int val);
Node *create_node(int val);
void dequeue(Queue *q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
int size(Queue *q);
int front(Queue *q);
void print_queue(Queue *q);

int main()
{
    int n;
    cin >> n;

    Queue *q = new Queue;
    q->max_size = n;

    while (true)
    {
        int id;
        cin >> id;

        if (id == -1)
        {
            cout << "Exit" << endl;
            break;
        }
        else if (id == 1)
        {
            cout << "EnQueue: ";
            int x;
            cin >> x;

            if (isFull(q))
            {
                cout << "Overflow" << endl;
            }
            else
            {
                enqueue(q, x);
                print_queue(q);
            }
        }
        else if (id == 2)
        {
            cout << "DeQueue: ";
            dequeue(q);
            print_queue(q);
        }
        else if (id == 3)
        {
            cout << "isEmpty: ";

            if (isEmpty(q))
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }
        else if (id == 4)
        {
            cout << "isFull: ";

            if (isFull(q))
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }
        else if (id == 5)
        {
            cout << "Size: ";
            cout << size(q) << endl;
        }
        else if (id == 6)
        {
            cout << "Front: ";

            if (!isEmpty(q))
                cout << front(q) << endl;
            else
                cout << "Empty" << endl;
        }
    }
}

Node *create_node(int val)
{
    Node *temp = new Node;
    temp->val = val;
    temp->next = NULL;

    return temp;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Overflow" << endl;
        return;
    }

    Node *temp = create_node(val);

    if (isEmpty(q))
    {
        q->curr_size++;
        q->head = temp;
        q->tail = temp;
        return;
    }

    q->curr_size++;

    q->tail->next = temp;
    q->tail = temp;

    return;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Underflow" << endl;
        return;
    }

    q->curr_size--;

    q->head = q->head->next;
}

bool isEmpty(Queue *q)
{
    if (q->curr_size == 0)
        return true;
    else
        return false;
}

bool isFull(Queue *q)
{
    if (q->curr_size == q->max_size)
        return true;
    else
        return false;
}

int size(Queue *q)
{
    return q->curr_size;
}

int front(Queue *q)
{
    return q->head->val;
}

void print_queue(Queue *q)
{
    if (isEmpty(q))
        return;
    Node *temp = q->head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}
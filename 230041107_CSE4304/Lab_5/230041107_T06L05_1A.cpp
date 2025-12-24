#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* prev;
};

struct Stack
{
    Node* head = NULL;
    Node* tail = NULL;
    int max_size;
    int curr_size = 0;
};

void push(Stack* s, int val);
Node* create_node(int val);
void pop(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
int size(Stack* s);
int top(Stack* s);
void print_stack(Stack* s);

int main()
{
    int n;
    cin >> n;

    Stack* s = new Stack;
    s->max_size = n;

    while (true)
    {
        int id;
        cin >> id;

        if(id == -1) break;
        else if(id == 1)
        {
            int x;
            cin >> x;

            push(s, x);
            print_stack(s);
        }
        else if(id == 2)
        {
            pop(s);
            print_stack(s);
        }
        else if(id == 3)
        {
            if(isEmpty(s)) cout << "True" << endl;
            else cout << "False" << endl; 
        }
        else if(id == 4)
        {
            if(isFull(s)) cout << "True" << endl;
            else cout << "False" << endl;
        }
        else if(id == 5)
        {
            cout << size(s) << endl;
        }
        else if(id == 6)
        {
            if(!isEmpty(s)) cout << top(s) << endl;
        }
    }
    
}


Node* create_node(int val)
{
    Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}


void push(Stack* s, int val)
{
    if(isFull(s))
    {
        cout << "Overflow" << endl;
        return;
    }

    Node* temp = create_node(val);

    if(isEmpty(s))
    {
        s->curr_size++;
        s->head = temp;
        s->tail = temp;
        return;
    }

    s->curr_size++;

    s->head->prev = temp;
    temp->next = s->head;
    s->head = temp;

    return;
}


void pop(Stack* s)
{
    if(isEmpty(s)) 
    {
        cout << "Underflow" << endl;
        return;
    }

    s->curr_size--;
    s->head = s->head->next;
    if(s->head == NULL)
    {
        s->tail = NULL;
    }
    else
    {
        s->head->prev = NULL;
    }
}


bool isEmpty(Stack* s)
{
    if(s->curr_size == 0) return true;
    else return false;
}


bool isFull(Stack* s)
{
    if(s->curr_size == s->max_size) return true;
    else return false;
}


int size(Stack* s)
{
    return s->curr_size;
}

int top(Stack* s)
{
    return s->head->val;
}


void print_stack(Stack* s)
{
    if(isEmpty(s)) return;
    Node* temp = s->tail;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }

    cout << endl;
}
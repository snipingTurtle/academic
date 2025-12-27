#include<iostream>

using namespace std;

int sz;

struct Node
{
    int val;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insert_front(int key);
void insert_back(int key);
int remove_head ();
int remove_end ();
Node* create_node(int key);
void print_list();
int get_size();

int main()
{
    int id;
    sz = 0;
    while(1)
    {
        cin >> id;

        if(id == 1)
        {
            int x;
            cin >> x;

            insert_front(x);
            print_list();
        }
        else if(id == 2)
        {
            int x;
            cin >> x;

            insert_back(x);
            print_list();
        }
        else if(id == 3)
        {
            remove_head();
            print_list();
        }
        else if(id == 4)
        {
            remove_end();
            print_list();
        }
        else if(id == 5)
        {
            get_size();
        }
        else if(id == 6) break;
    }
}


Node* create_node(int key)
{
    Node* temp = new Node;
    temp->val = key;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void insert_front(int key)
{
    Node* n = create_node(key);
    sz++;
    if(head == NULL)
    {
        head = n;
        tail = n;
        return;
    }

    head->prev  = n;
    n->next = head;
    head = n;

    return;
}


void insert_back(int key)
{
    sz++;
    Node* temp = create_node(key);
    if(tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

int remove_head()
{
    if(head == NULL)
    {
        cout << "Underflow" << endl;
        return 0;
    }
    int ans = head->val;
    sz--;
    head = head->next;
    head->prev = NULL;
    return ans;
}

int remove_end ()
{
    if(sz == 0)
    {
        cout << "Underflow" << endl;
        return 0;
    }
    sz--;
    int ans = tail->val;
    if(tail == head)
    {
        tail = NULL;
        head = NULL;
        return ans;
    }

    tail = tail->prev;
    tail->next = NULL;
    return ans;
}

int get_size()
{
    cout << sz << " ";
    return sz;
}

void print_list()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

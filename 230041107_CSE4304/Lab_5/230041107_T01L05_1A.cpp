#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insert_front(int key);
void insert_back(int key);
void insert_after_node (int key,  int v);
void update_node (int key, int v);
void remove_head ();
void remove_element (int key);
void remove_end ();
void print_status();
Node* create_node(int key);
void print_head();
void print_tail();
void print_list();

int main()
{
    int id;
    while(1)
    {
        cin >> id;

        if(id == 1)
        {
            int x;
            cin >> x;

            insert_front(x);
        }
        else if(id == 2)
        {
            int x;
            cin >> x;

            insert_back(x);
        }
        else if(id == 3)
        {
            int v, key;
            cin >> key >> v;

            insert_after_node(key, v);
        }
        else if(id == 4)
        {
            int key, v;
            cin >> key >> v;

            update_node(key, v);
        }
        else if(id == 5)
        {
            remove_head();
        }
        else if(id == 6)
        {
            int key;
            cin >> key;

            remove_element(key);
        }
        else if(id == 7)
        {
            remove_end();
        }
        else if(id == 8) break;
        print_status();
    }
}


Node* create_node(int key)
{
    Node* temp = new Node;
    temp->val = key;
    temp->next = NULL;

    return temp;
}

void insert_front(int key)
{
    Node* n = create_node(key);
    if(head == NULL)
    {
        head = n;
        tail = n;
        return;
    }

    n->next = head;
    head = n;

    return;
}


void insert_back(int key)
{
    Node* temp = create_node(key);
    if(tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}


void insert_after_node (int key,  int v)
{
    Node* temp = create_node(key);

    Node* nxt = head;
    while((nxt != NULL) && (nxt->val != v))
    {
        nxt = nxt->next;
    }

    if(nxt == NULL)
    {
        cout << "Value Not Found" << endl;
        return;
    }

    temp->next = nxt->next;
    nxt->next = temp;
}

void update_node (int key, int v)
{
    Node* nxt = head;
    while((nxt != NULL) && (nxt->val != v))
    {
        nxt = nxt->next;
    }

    if(nxt == NULL)
    {
        cout << "Value Not Found" << endl;
        return;
    }

    nxt->val = key;
}

void remove_head()
{
    if(head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    head = head->next;
}

void remove_element (int key)
{
    Node* nxt = head;
    Node* prev = nxt;
    while((nxt != NULL) && (nxt->val != key))
    {
        prev = nxt;
        nxt = nxt->next;
    }

    if(nxt == NULL)
    {
        cout << "Value Not Found" << endl;
        return;
    }

    prev->next = nxt->next;
}


void remove_end ()
{
    Node* temp = head;
    Node* prev = NULL;
    if(temp == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == head)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    prev->next = NULL;
    tail = prev;
}

void print_status()
{
    print_head();
    print_tail();
    print_list();
}


void print_head()
{
    if(head == NULL)
    {
        cout << "Head=Null, ";
    }
    else cout << "Head=" << head->val << ", ";
}

void print_tail()
{
    if(tail == NULL)
    {
        cout << "Tail=Null, ";
    }
    else cout << "Tail=" << tail->val << ", ";
}

void print_list()
{
    Node* temp = head;
    if(head == NULL) cout << "Empty" << endl;
    else
    {
        while(temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

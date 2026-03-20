#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct LinkedList
{
    Node *head = NULL;
    Node *tail = NULL;
};

void insert_back(LinkedList *l, int key);
Node *create_node(int key);
void print_list(LinkedList *l);
void add(LinkedList *l1, LinkedList *l2);

int main()
{
    LinkedList *odd = new LinkedList;
    LinkedList *even = new LinkedList;

    int pos = 1;

    while (1)
    {
        string s;
        cin >> s;

        if (s == "NULL")
            break;
        if (pos % 2)
            insert_back(odd, s[0] - '0');
        else
            insert_back(even, s[0] - '0');
        pos++;
    }

    add(odd, even);
    print_list(odd);
}

Node *create_node(int key)
{
    Node *temp = new Node;
    temp->val = key;
    temp->next = NULL;

    return temp;
}

void insert_back(LinkedList *l, int key)
{
    Node *temp = create_node(key);
    if (l->tail == NULL)
    {
        l->head = temp;
        l->tail = temp;
        return;
    }

    l->tail->next = temp;
    l->tail = temp;
}

void print_list(LinkedList *l)
{
    Node *temp = l->head;
    if (l->head == NULL)
        cout << "Empty" << endl;
    else
    {
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void add(LinkedList *l1, LinkedList *l2)
{
    l1->tail->next = l2->head;
    l1->tail = l2->tail;
}
#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Linked_List
{
    Node *head = NULL;
    Node *tail = NULL;
};

void insert_back(int key, Linked_List *l);
Node *create_node(int key);
void print_list(Linked_List *l);

int main()
{
    Linked_List *l1 = new Linked_List;
    Linked_List *l2 = new Linked_List;

    while (true)
    {
        int x;
        cin >> x;

        if (x == -1)
            break;
        insert_back(x, l1);
    }

    while (true)
    {
        int x;
        cin >> x;

        if (x == -1)
            break;
        insert_back(x, l2);
    }

    Linked_List *intersected = new Linked_List;

    Node *p1 = l1->head;
    Node *p2 = l2->head;

    while ((p1 != NULL) && (p2 != NULL))
    {
        if (p1->val > p2->val)
        {
            p2 = p2->next;
        }
        else if (p1->val < p2->val)
        {
            p1 = p1->next;
        }
        else
        {
            insert_back(p1->val, intersected);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    print_list(intersected);
}

Node *create_node(int key)
{
    Node *temp = new Node;
    temp->val = key;
    temp->next = NULL;

    return temp;
}

void insert_back(int key, Linked_List *l)
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

void print_list(Linked_List *l)
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
        cout << endl;
    }
}
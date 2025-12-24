#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insert_back(int key);
Node *create_node(int key);
void remove_duplicate();
void print_list();

int main()
{
    while (1)
    {
        int x;
        cin >> x;

        if (x == -1)
            break;
        insert_back(x);
    }

    remove_duplicate();
    print_list();
}

Node *create_node(int key)
{
    Node *temp = new Node;
    temp->val = key;
    temp->next = NULL;

    return temp;
}

void insert_back(int key)
{
    Node *temp = create_node(key);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void remove_duplicate()
{
    Node *temp = head;
    while (temp != NULL)
    {
        while (temp->next != NULL)
        {
            if (temp->val != temp->next->val)
                break;
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void print_list()
{
    Node *temp = head;
    if (head == NULL)
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
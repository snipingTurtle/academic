#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node* parent = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
    int height = 0;
};

Node* tree_root = NULL;

Node* create_node(int val)
{
    Node* temp = new Node;
    temp->val = val;

    return temp;
}

int get_height(Node* curr)
{
    if(curr == NULL) return -1;
    else return curr->height;
}

void update_height(Node* curr)
{
    Node* temp = curr;
    while (temp != NULL)
    {
        temp->height = max(get_height(temp->left_child), get_height(temp->right_child)) + 1;
        temp = temp->parent;
    }
}

void insert_node(int val)
{
    Node* newNode = create_node(val);
    Node* temp = tree_root;
    if(temp == NULL)
    {
        tree_root = newNode;
        return;
    }

    Node* target = temp;

    while(temp != NULL)
    {
        target = temp;
        if(newNode->val < temp->val)
        {
            temp = temp->left_child;
        }
        else
        {
            temp = temp->right_child;
        }
    }

    newNode->parent = target;
    if(newNode->val < target->val) target->left_child = newNode;
    else target->right_child = newNode;
    update_height(newNode);
}

int balance_factor(Node* curr)
{

    if(curr == NULL) return 0;
    int balance = get_height(curr->left_child) - get_height(curr->right_child);
    return balance;
}

void inorder_print(Node* curr)
{
    if(curr == NULL) return;

    inorder_print(curr->left_child);

    cout << curr->val;
    cout << "(" << balance_factor(curr) << ") ";

    inorder_print(curr->right_child);
}

int main()
{
    while(1)
    {
        int x;
        cin >> x;

        if(x == -1) break;

        insert_node(x);
        inorder_print(tree_root);
        cout << endl;
    }
}

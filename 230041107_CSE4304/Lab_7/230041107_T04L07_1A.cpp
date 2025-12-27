#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *parent = NULL;
    Node *left_child = NULL;
    Node *right_child = NULL;
    int height = 0;
    int size = 1;
};

Node *tree_root = NULL;

Node *create_node(int val);
void insert_node(int val);
int get_height(Node *curr);
int get_size(Node *curr);
void update_height(Node *curr);
void check_balance(Node *newNode);
void balance_node(Node *newNode, Node *curr, int balance);
int balance_factor(Node *curr);
void left_rotate(Node *z);
void right_rotate(Node *z);
int lowerCount(int key);

void print_avl(Node *curr)
{
    if (curr == NULL)
        return;

    print_avl(curr->left_child);

    cout << curr->val;
    if (curr->parent != NULL)
        cout << "(" << curr->parent->val << ")(" << get_size(curr) << ") ";
    else
        cout << "(NULL)(" << get_size(curr) << ") ";

    print_avl(curr->right_child);
}

int main()
{
    while (1)
    {
        int x;
        cin >> x;

        if (x == -1)
            break;

        insert_node(x);
    }

    while (1)
    {
        int x;
        cin >> x;

        if (x == -1)
            break;

        cout << lowerCount(x) << endl;
    }
}

Node *create_node(int val)
{
    Node *temp = new Node;
    temp->val = val;

    return temp;
}

void insert_node(int val)
{
    Node *newNode = create_node(val);
    Node *temp = tree_root;
    if (temp == NULL)
    {
        tree_root = newNode;
        check_balance(newNode);
        return;
    }

    Node *target = temp;

    while (temp != NULL)
    {
        target = temp;
        if (newNode->val < temp->val)
        {
            temp = temp->left_child;
        }
        else
        {
            temp = temp->right_child;
        }
    }

    newNode->parent = target;
    if (newNode->val < target->val)
        target->left_child = newNode;
    else
        target->right_child = newNode;

    update_height(newNode);
    check_balance(newNode);
}

int get_height(Node *curr)
{
    if (curr == NULL)
        return -1;
    else
        return curr->height;
}

int get_size(Node *curr)
{
    if (curr == NULL)
        return 0;
    else
        return curr->size;
}

void update_height(Node *curr)
{
    Node *temp = curr;
    while (temp != NULL)
    {
        temp->height = max(get_height(temp->left_child), get_height(temp->right_child)) + 1;
        temp->size = get_size(temp->left_child) + get_size(temp->right_child) + 1;
        temp = temp->parent;
    }
}

void left_rotate(Node *z)
{
    Node *y = z->right_child;
    Node *yL = y->left_child;

    y->parent = z->parent;
    if (z == tree_root)
        tree_root = y;
    else if (z == z->parent->left_child)
        y->parent->left_child = y;
    else
        y->parent->right_child = y;

    y->left_child = z;
    z->parent = y;

    z->right_child = yL;
    if (yL != NULL)
        yL->parent = z;

    update_height(z);
}

void right_rotate(Node *z)
{
    Node *y = z->left_child;
    Node *yR = y->right_child;

    y->parent = z->parent;
    if (z == tree_root)
        tree_root = y;
    else if (z == z->parent->left_child)
        y->parent->left_child = y;
    else
        y->parent->right_child = y;

    y->right_child = z;
    z->parent = y;

    z->left_child = yR;
    if (yR != NULL)
        yR->parent = z;

    update_height(z);
}

void check_balance(Node *newNode)
{
    Node *temp = newNode;

    while (temp != NULL)
    {
        int balance = balance_factor(temp);

        if ((balance < -1) || (balance > 1))
        {
            balance_node(newNode, temp, balance);
            break;
        }
        else
            temp = temp->parent;
    }
}

int balance_factor(Node *curr)
{

    if (curr == NULL)
        return 0;
    int balance = get_height(curr->left_child) - get_height(curr->right_child);
    return balance;
}

void balance_node(Node *newNode, Node *curr, int balance)
{
    if (balance > 1)
    {
        if (newNode->val < curr->left_child->val)
        {
            right_rotate(curr);
        }
        else if (newNode->val > curr->left_child->val)
        {
            left_rotate(curr->left_child);
            right_rotate(curr);
        }
    }

    if (balance < -1)
    {
        if (newNode->val > curr->right_child->val)
        {
            left_rotate(curr);
        }
        else if (newNode->val < curr->right_child->val)
        {
            right_rotate(curr->right_child);
            left_rotate(curr);
        }
    }
}

int lowerCount(int key)
{
    Node *temp = tree_root;

    int res = 0;

    while (temp != NULL)
    {
        // cout << temp->val << " ";
        if (temp->val == key)
        {
            res += get_size(temp->left_child);
            break;
        }
        else if (temp->val < key)
        {
            res += (get_size(temp->left_child) + 1);
            temp = temp->right_child;
        }
        else
            temp = temp->left_child;
        // cout << res << "\n";
    }

    return res;
}
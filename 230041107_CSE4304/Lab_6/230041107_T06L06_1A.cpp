#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int val;
    Node* parent = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
};

Node* tree_root = NULL;

Node* create_node(int val)
{
    Node* temp = new Node;
    temp->val = val;

    return temp;
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
        if(newNode->val < temp->val) temp = temp->left_child;
        else temp = temp->right_child;
    }

    newNode->parent = target;
    if(newNode->val < target->val) target->left_child = newNode;
    else target->right_child = newNode;
}


void inorder_print(Node* curr, bool flag)
{
    if(curr == NULL) return;

    inorder_print(curr->left_child, false);

    if(!flag) cout << curr->val << " ";

    inorder_print(curr->right_child, false);
}

Node* searching(int key)
{
    Node* temp = tree_root;
    while((temp != NULL) && (temp->val != key))
    {
        if(key > temp->val) temp = temp->right_child;
        else temp = temp->left_child;
    }

    return temp;
}

void print_ancestor(Node* curr)
{
    if(curr == NULL) cout << "Invalid" << endl;
    else if(curr->parent == NULL) cout << "NULL" << endl;
    else
    {
        Node* temp = curr->parent;

        while(temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->parent;
        }
        cout << endl;
    }
}

void print_descendant(Node* curr)
{
    if(curr == NULL) cout << "Invalid" << endl;
    else if((curr->left_child == NULL) && (curr->right_child == NULL)) cout << "NULL" << endl;
    else
    {
        inorder_print(curr, true);
        cout << endl;
    }
}

int main()
{
    int cnt = 0;
    while(1)
    {
        int x;
        cin >> x;

        if(x == -1) break;

        insert_node(x);
        cnt++;
    }


    inorder_print(tree_root, false);
    cout << endl;

    while(cnt--)
    {
        int x;
        cin >> x;

        Node* curr = searching(x);
        print_ancestor(curr);
        print_descendant(curr);
    }
}

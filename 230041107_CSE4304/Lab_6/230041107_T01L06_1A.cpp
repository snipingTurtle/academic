#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int val;
    Node* parent = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
    int level = 0;
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
        tree_root->level = 1;
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
    newNode->level = newNode->parent->level + 1;
    if(newNode->val < target->val) target->left_child = newNode;
    else target->right_child = newNode;
}


void inorder_print(Node* curr)
{
    if(curr == NULL) return;

    inorder_print(curr->left_child);

    cout << curr->val;
    if(curr->parent == NULL) cout << "(null) ";
    else cout << "(" << curr->parent->val << ") ";

    inorder_print(curr->right_child);
}

void preorder_print(Node* curr)
{
    if(curr == NULL) return;

    cout << curr->val;
    if(curr->parent == NULL) cout << "(null) ";
    else cout << "(" << curr->parent->val << ") ";

    preorder_print(curr->left_child);

    preorder_print(curr->right_child);
}

void postorder_print(Node* curr)
{
    if(curr == NULL) return;

    postorder_print(curr->left_child);

    postorder_print(curr->right_child);

    cout << curr->val;
    if(curr->parent == NULL) cout << "(null) ";
    else cout << "(" << curr->parent->val << ") ";
}

void level_print(Node* curr)
{
    int lvl = 1;
    queue<Node*> q;
    q.push(curr);

    cout << "Level 1: ";

    while(!q.empty())
    {
        Node* temp = q.front();
        if(temp->level != lvl)
        {
            lvl = temp->level;
            cout << endl;
            cout << "Level " << lvl << ": ";
        }
        if(temp->left_child != NULL) q.push(temp->left_child);
        if(temp->right_child != NULL) q.push(temp->right_child);

        cout << temp->val;
        if(temp->parent != NULL) cout << "(" << temp->parent->val << ") ";
        else cout << "(null) ";

        q.pop();
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        insert_node(x);
    }

    cout << "Inorder:" << endl;
    inorder_print(tree_root);
    cout << endl;

    cout << "Preorder:" << endl;
    preorder_print(tree_root);
    cout << endl;

    cout << "Postorder:" << endl;
    postorder_print(tree_root);
    cout << endl;

    level_print(tree_root);
    cout << endl;
}

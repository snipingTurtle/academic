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

    int q;
    cin>>q;

    while(q--)
    {
        int a, b;
        cin>>a>>b;

        Node* anode = searching(a);
        Node* bnode = searching(b);
        

        if((anode == NULL) || (bnode == NULL)) cout << "Inavalid" << endl;
        else
        {
            while(anode->level > bnode->level) anode = anode->parent;
            while (bnode->level > anode->level) bnode = bnode->parent;
            while(anode->val != bnode->val)
            {
                anode = anode->parent;
                bnode = bnode->parent;
            }

            cout << anode->val << endl;
        }
    }
}
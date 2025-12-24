#include<iostream>
#include<queue>
#include<stack>

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

int diameter = 0;

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
        int z = (get_height(temp->left_child) + 1) + get_height(temp->right_child) + 1;
        diameter = max(diameter, z + 1);
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

int main()
{
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;

        insert_node(x);
    }

    cout << diameter << endl;
}

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
    int cnt_left = 0;
    int cnt_right = 0;
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
        if(newNode->val < temp->val)
        {
            temp->cnt_left++;
            temp = temp->left_child;
        }
        else
        {
            temp->cnt_right++;
            temp = temp->right_child;
        }
    }

    newNode->parent = target;
    if(newNode->val < target->val) target->left_child = newNode;
    else target->right_child = newNode;
}

void inorder_print(vector<int> &v, Node* curr)
{
    if(curr == NULL) return;

    inorder_print(v, curr->left_child);

    if((curr->left_child == NULL) && (curr->right_child == NULL)) v.emplace_back(curr->val);

    inorder_print(v, curr->right_child);
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) 
    {
        int x;
        cin >> x;

        
        insert_node(x);
    }

    vector<int> v;
    inorder_print(v, tree_root);
    cout << "Leaf nodes:" << endl;
    for(int i = 0; i < (int)v.size() - 1; i++) cout << v[i] << ", ";
    cout << v.back() << endl;
}

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

void print_element(Node* curr, int k)
{
    if(curr == NULL) {
        cout << "Invalid" << endl;
        return;
    }

    int n = curr->cnt_left + 1;
    if(n == k) cout << curr->val << endl;
    else if(n > k) print_element(curr->left_child, k);
    else print_element(curr->right_child, k - n);
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

    int q;
    cin >> q;

    while(q--)
    {
        int k;
        cin >> k;

        print_element(tree_root, k);
    }
}

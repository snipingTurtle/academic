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
    int level = 0;
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
        tree_root->level = 1;
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
    newNode->level = newNode->parent->level + 1;
    if(newNode->val < target->val) target->left_child = newNode;
    else target->right_child = newNode;
    update_height(newNode);
}


void inorder_print(Node* curr)
{
    if(curr == NULL) return;

    inorder_print(curr->left_child);

    cout << curr->val;
    cout << "(" << curr->height << ") ";

    inorder_print(curr->right_child);
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
    while (1)
    {
        int x;
        cin >> x;

        if(x == -1) break;
        insert_node(x);
    }
    
    cout << "Status: ";
    inorder_print(tree_root);
    cout << endl;

    while (1)
    {
        int x, y;
        cin >> x >> y;

        if(x  == -1) break;

        Node* a = searching(x);
        Node* b = searching(y);

        if((a == NULL) || (b == NULL))
        {
            cout << "Invalid" << endl;
            continue;
        }

        queue<int> before;
        stack<int> after;

        while(a->level > b->level) 
        {
            before.push(a->val);
            a = a->parent;
        }

        while (a->level < b->level)
        {
            after.push(b->val);
            b = b->parent;
        }
        
        while (a->val != b->val)
        {
            before.push(a->val);
            after.push(b->val);

            a = a->parent;
            b = b->parent;
        }
        
        int cnt = 1;

        while (!before.empty())
        {
            cout << before.front() << " ";
            before.pop();
            cnt++;
        }
        
        cout << a->val << " ";

        while (!after.empty())
        {
            cout << after.top() << " ";
            after.pop();
            cnt++;
        }

        cout << endl;

        cout << cnt << endl;
    }
}

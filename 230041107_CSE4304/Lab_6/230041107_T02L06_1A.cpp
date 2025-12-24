#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int val;
    Node* parent = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
    int lHeight = -1;
    int rHeight = -1;
    int height = 0;
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
            temp = temp->left_child;
            target->lHeight++;
        }
        else
        {
            temp = temp->right_child;
            target->rHeight++;
        }
        target->height = max(target->lHeight, target->rHeight) + 1;
    }

    newNode->parent = target;
    if(newNode->val < target->val) target->left_child = newNode;
    else target->right_child = newNode;
}


void inorder_print(Node* curr)
{
    if(curr == NULL) return;

    inorder_print(curr->left_child);

    cout << curr->val << " ";

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

Node* tree_min(Node* curr)
{
    if(curr == NULL) return curr;
    Node* temp = curr;
    while(temp->left_child != NULL)
    {
        temp = temp->left_child;
    }

    return temp;
}

Node* tree_max(Node* curr)
{
    if(curr == NULL) return curr;
    Node* temp = curr;
    while(temp->right_child != NULL)
    {
        temp = temp->right_child;
    }

    return temp;
}

Node* after(Node* x)
{
    if(x == tree_max(tree_root)) return NULL;

    if(x->right_child != NULL) return tree_min(x->right_child);

    Node* temp = x->parent;
    while(temp->val < x->val)
    {
        temp = temp->parent;
    }

    return temp;
}

Node* before(Node* x)
{
    if(x == tree_min(tree_root)) return NULL;

    if(x->left_child != NULL) return tree_max(x->left_child);

    Node* temp = x->parent;
    while(temp->val > x->val)
    {
        temp = temp->parent;
    }

    return temp;
}

int main()
{
    while(1)
    {
        int id;
        cin >> id;
        if(id == -1) break;
        else if(id == 1)
        {
            int x;
            cin >> x;

            insert_node(x);
            inorder_print(tree_root);
            cout << endl;
        }
        else if(id == 2)
        {
            inorder_print(tree_root);
            cout << endl;
        }
        else if(id == 3)
        {
            int x;
            cin >> x;

            Node* curr = searching(x);
            if(curr == NULL) cout << "Not found" << endl;
            else
            {
                cout << "Present" << endl;
                if(curr->parent != NULL) cout << "Parent(" << curr->parent->val << "), ";
                else cout << "Parent(null), ";

                if(curr->left_child != NULL) cout << "Left(" << curr->left_child->val << "), ";
                else cout << "Left(null), ";

                if(curr->right_child != NULL) cout << "Right(" << curr->right_child->val << ")" << endl;
                else cout << "Right(null)" << endl;;
            }
        }
        else if(id == 4)
        {
            int x;
            cin >> x;

            Node* curr = searching(x);

            if(curr == NULL) cout << "Not found" << endl;
            else cout << curr->height << endl;
        }
        else if(id == 5)
        {
            int x;
            cin >> x;

            Node* curr = searching(x);
            if(curr == NULL) cout << "Not found" << endl;
            else
            {
                Node* bef = before(curr);
                Node* af = after(curr);

                if(bef != NULL) cout << bef->val << " ";
                else cout << "null ";
                if(af != NULL) cout << af->val << " ";
                else cout << "null ";
            }
        }
        else if(id == 6)
        {
            int x;
            cin >> x;

            Node* curr = searching(x);
            if(curr == NULL) cout << "Not found" << endl;
            else
            {
                Node* mn = tree_min(curr);
                Node* mx = tree_max(curr);

                if(mn != NULL) cout << mn->val << " ";
                else cout << "null ";
                if(mx != NULL) cout << mx->val << " ";
                else cout << "null ";
            }
        }
    }
}

#include<iostream>
#include<string>

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

Node* create_node(int val);
void insert_node(int val);
int get_height(Node* curr);
void update_height(Node* curr);
void check_balance(Node* newNode);
void balance_node(Node* newNode, Node* curr, int balance);
int balance_factor(Node* curr);
void left_rotate(Node* z);
void right_rotate(Node* z);
Node* searching(int key);
void deletion (int key);
void transplant(Node* u, Node* v);
Node* tree_min(Node* curr);
void del_check_balance(Node* curr);
void print_avl(Node* curr);

int main()
{
    while(1)
    {
        string s;
        cin >> s;

        if(s == "-1")
        {
            print_avl(tree_root);
            cout << endl;
            break;
        }
        else if((int)s.size() != 6)
        {
            int x = stoi(s);

            insert_node(x);
            cout << "Root=" << tree_root->val << endl;
        }
        else
        {
            int x;
            cin >> x;

            deletion(x);
            cout << "Root=" << tree_root->val << endl;
        }
    }
}

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
        print_avl(tree_root);
        cout << endl;
        check_balance(newNode);
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

    print_avl(tree_root);
    cout << endl;
    check_balance(newNode);
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

void left_rotate(Node* z)
{
    cout << "left_rotate(" << z->val << ")" << endl;
    Node* y = z->right_child;
    Node* yL = y->left_child;

    y->parent = z->parent;
    if(z == tree_root) tree_root = y;
    else if(z == z->parent->left_child) y->parent->left_child = y;
    else y->parent->right_child = y;

    y->left_child = z;
    z->parent = y;

    z->right_child = yL;
    if(yL != NULL) yL->parent = z;

    update_height(z);
}

void right_rotate(Node* z)
{
    cout << "right_rotate(" << z->val << ")" << endl;
    Node* y = z->left_child;
    Node* yR = y->right_child;

    y->parent = z->parent;
    if(z == tree_root) tree_root = y;
    else if(z == z->parent->left_child) y->parent->left_child = y;
    else y->parent->right_child = y;

    y->right_child = z;
    z->parent = y;

    z->left_child = yR;
    if(yR != NULL) yR->parent = z;

    update_height(z);
}

void check_balance(Node* newNode)
{
    Node* temp = newNode;

    while(temp != NULL)
    {
        int balance = balance_factor(temp);

        if((balance < -1) || (balance > 1))
        {
            balance_node(newNode, temp, balance);
            break;
        }
        else temp = temp->parent;
    }

    if(temp == NULL) cout << "Balanced" << endl;
}

int balance_factor(Node* curr)
{
    
    if(curr == NULL) return 0;
    int balance = get_height(curr->left_child) - get_height(curr->right_child);
    return balance;
}

void balance_node(Node* newNode, Node* curr, int balance)
{
    cout << "Imbalance at node: " << curr->val << endl;
    if(balance > 1)
    {
        if(newNode->val < curr->left_child->val)
        {
            cout << "LL case" << endl;
            right_rotate(curr);
        }
        else if(newNode->val > curr->left_child->val)
        {
            cout << "LR case" << endl;
            left_rotate(curr->left_child);
            right_rotate(curr);
        }
    }
    
    if(balance < -1)
    {
        if(newNode->val > curr->right_child->val)
        {
            cout << "RR case" << endl;
            left_rotate(curr);
        }
        else if(newNode->val < curr->right_child->val)
        {
            cout << "RL case" << endl;
            right_rotate(curr->right_child);
            left_rotate(curr);
        }
    }
    
    cout << "Status: ";
    print_avl(tree_root);
    cout << endl;
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

void transplant(Node* u, Node* v)
{
    if(u->parent == NULL)
    {
        tree_root = v;
    }
    else if(u == u->parent->left_child)
    {
        u->parent->left_child = v;
    }
    else
    {
        u->parent->right_child = v;
    }
    
    if(v != NULL) v->parent = u->parent;
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

void del_check_balance(Node* curr)
{
    while(curr != NULL)
    {
        int balance = balance_factor(curr);
        
        if((balance > 1) || (balance < -1))
        {
            cout << "Imabalanced node: " << curr->val << endl;
            
            if(balance > 1) 
            {
                right_rotate(curr);
            }
            else left_rotate(curr);

            print_avl(tree_root);
            cout << endl;
            
            break;
        }
        else curr = curr->parent;
    }

    if(curr == NULL) cout << "Balanced" << endl;
}

void deletion (int key)
{
    Node* z = searching(key);
    if(z == NULL) cout << "Invalid" << endl;
    else
    {
        if(z->left_child == NULL)
        {
            transplant(z, z->right_child);
            print_avl(tree_root);
            cout << endl;
            update_height(z->parent);
            del_check_balance(z->parent);
        }
        else if(z->right_child == NULL)
        {
            transplant(z, z->left_child);
            print_avl(tree_root);
            cout << endl;
            update_height(z->parent);
            del_check_balance(z->parent);
        }
        else
        {
            Node* y = tree_min(z->right_child);
            Node* temp = z->parent;
            
            if(y->parent != z)
            {
                if(y->right_child != NULL) temp = y->right_child;
                transplant(y, y->right_child);
                y->right_child = z->right_child;
                z->right_child->parent = y;
            }
            
            transplant(z, y);
            y->left_child = z->left_child;
            z->left_child->parent = y;
            
            print_avl(tree_root);
            cout << endl;
            update_height(temp);
            del_check_balance(temp);
        }
    }
}

void print_avl(Node* curr)
{
    if(curr == NULL) return;

    print_avl(curr->left_child);

    cout << curr->val;
    cout << "(" << balance_factor(curr) << ") ";

    print_avl(curr->right_child);
}
# DS_Lab_Mid_Template

## Lab 2

### Stack

```cpp
int tp = -1;
void print_stack(int stack[])
{
    for (int i = 0; i <= tp; i++)
        cout << stack[i] << " ";
    cout << "\n";
}

void push(int stack[], int x, int n)
{
    if (isFull(n))
        cout << "Overflow\n";
    else
    {
        tp++;
        stack[tp] = x;
        print_stack(stack);
    }
}

void pop(int stack[])
{
    if (isEmpty())
        cout << "Underflow\n";
    else
    {
        tp--;
        print_stack(stack);
    }
}

int isEmpty()
{
    if (tp == -1)
        return 1;
    else
        return 0;
}

int isFull(int n)
{
    if ((tp + 1) == n)
        return 1;
    else
        return 0;
}

int size()
{
    return tp + 1;
}

int top(int stack[])
{
    return stack[tp];
}

```

---

## Lab 3

### Queue

```cpp
int queue[n];

int front = 0;
int rear = 0;
int cnt = 0;

void print_queue(int queue[], int front, int cnt, int Maxq)
{
    for (int i = 0; i < cnt; i++)
    {
        int x = (front + i) % Maxq;
        cout << queue[x] << " ";
    }
    cout << endl;
}

void EnQueue(int queue[], int &front, int &rear, int &cnt, int value, int Maxq)
{
    if (cnt == Maxq)
    {
        cout << "EnQueue: Overflow" << endl;
        return;
    }
    cnt++;
    queue[rear] = value;
    rear = (rear + 1) % Maxq;

    cout << "EnQueue: ";
    print_queue(queue, front, cnt, Maxq);
}

void DeQueue(int queue[], int &front, int &cnt, int Maxq)
{
    if (cnt == 0)
    {
        cout << "DeQueue: Underflow" << endl;
        ;
        return;
    }

    cnt--;
    front = (front + 1) % Maxq;

    cout << "DeQueue: ";
    print_queue(queue, front, cnt, Maxq);
}

int isEmpty(int cnt)
{
    if (cnt == 0)
        return 1;
    else
        return 0;
}

int isFull(int cnt, int Maxq)
{
    if (cnt == Maxq)
        return 1;
    else
        return 0;
}

int q_size(int cnt)
{
    return cnt;
}

int q_front(int queue[], int front)
{
    return queue[front];
}
```

### Deque

```cpp
const int MAXN = 1e6 + 1;

int front = 0;
int rear = 1;
int cnt = 0;

int deque[MAXN];

void print_queue()
{
    for (int i = 0; i < cnt; i++)
    {
        int pos = (i + front + 1) % (MAXN - 1);
        cout << deque[pos] << " ";
    }
    cout << endl;
}

void push_front(int key)
{
    if (cnt == (MAXN - 1))
        cout << "Overflow" << endl;
    else
    {
        deque[front] = key;
        front--;
        front = (front + MAXN - 1) % (MAXN - 1);
        cnt++;
        print_queue();
    }
}

void push_back(int key)
{
    if (cnt == (MAXN - 1))
        cout << "Overflow" << endl;
    else
    {
        deque[rear] = key;
        rear = (rear + 1) % (MAXN - 1);
        cnt++;
        print_queue();
    }
}

int pop_front()
{
    if (cnt == 0)
        cout << "Underflow" << endl;
    else
    {
        int res = deque[front];
        front = (front + 1) % (MAXN - 1);
        cnt--;
        print_queue();
        return res;
    }
}

int pop_back()
{
    if (cnt == 0)
        cout << "Underflow" << endl;
    else
    {
        int res = deque[rear];
        rear--;
        rear = (rear + MAXN - 1) % (MAXN - 1);
        cnt--;
        print_queue();

        return res;
    }
}

int size()
{
    return cnt;
}
```

---

## Lab 4

### Heap

```cpp
const int MAXN = 1e6 + 1;

int n = 0;

void max_heapify(int heap[], int parent)
{
    int L_child = 2 * parent;
    int R_child = (2 * parent) + 1;

    int largest;

    if ((L_child <= n) && (heap[L_child] > heap[parent]))
    {
        largest = L_child;
    }
    else
        largest = parent;

    if ((R_child <= n) && (heap[R_child] > heap[largest]))
    {
        largest = R_child;
    }

    if (largest != parent)
    {
        int temp = heap[largest];
        heap[largest] = heap[parent];
        heap[parent] = temp;

        max_heapify(heap, largest);
    }
}

void build_max_heap(int heap[])
{
    for (int i = n / 2; i > 0; i--)
    {
        max_heapify(heap, i);
    }
}

int Heap_Maximum(int heap[])
{
    if (n < 1)
        return -1;
    return heap[1];
}

int Heap_extract_max(int heap[])
{
    if (n < 1)
        return -1;
    int res = heap[1];

    heap[1] = heap[n];
    n--;

    if (n > 0)
        max_heapify(heap, 1);

    return res;
}

void Max_heap_insert(int value, int heap[])
{
    n++;
    heap[n] = value;

    reverse_heapify(n, heap);
}

void Heap_decrease_key(int i, int k, int heap[])
{
    if (i > n)
        return;
    heap[i] -= k;

    max_heapify(heap, i);
}

void Heap_increase_key(int i, int k, int heap[])
{
    if (i > n)
        return;
    heap[i] += k;

    reverse_heapify(i, heap);
}

void reverse_heapify(int n, int heap[])
{
    if (n <= 1)
        return;
    int parent = n / 2;

    if (heap[n] > heap[parent])
    {
        int temp = heap[parent];
        heap[parent] = heap[n];
        heap[n] = temp;

        reverse_heapify(parent, heap);
    }
    else
        return;
}

void heap_sort(int n)
{
    int sz = n;
    for(int i = 1; i < n; i++)
    {
        int temp = ar[1];
        ar[1] = ar[sz];
        ar[sz] = temp;

        sz--;
        max_heapify(1, sz);
    }
}
```

---

## Lab 5

### Linked List

```cpp
struct Node
{
    int val;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

Node *create_node(int key)
{
    Node *temp = new Node;
    temp->val = key;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void insert_front(int key)
{
    Node *n = create_node(key);
    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }

    head->prev = n;
    n->next = head;
    head = n;

    return;
}

void insert_back(int key)
{
    Node *temp = create_node(key);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insert_after_node(int key, int v)
{
    Node *temp = create_node(key);

    Node *nxt = head;
    while ((nxt != NULL) && (nxt->val != v))
    {
        nxt = nxt->next;
    }

    if (nxt == NULL)
    {
        cout << "Value Not Found" << endl;
        return;
    }

    if (nxt->next != NULL)
    {
        nxt->next->prev = temp;
    }
    else
    {
        tail = temp;
    }
    temp->next = nxt->next;
    temp->prev = nxt;
    nxt->next = temp;
}

void update_node(int key, int v)
{
    Node *nxt = head;
    while ((nxt != NULL) && (nxt->val != v))
    {
        nxt = nxt->next;
    }

    if (nxt == NULL)
    {
        cout << "Value Not Found" << endl;
        return;
    }

    nxt->val = key;
}

void remove_head()
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    head = head->next;
    head->prev = NULL;
}

void remove_element(int key)
{
    Node *nxt = head;
    while ((nxt != NULL) && (nxt->val != key))
    {
        nxt = nxt->next;
    }

    if (nxt == NULL)
    {
        cout << "Value Not Found" << endl;
        return;
    }

    if ((nxt == head) && (nxt == tail))
    {
        head = NULL;
        tail = NULL;
        return;
    }

    if (nxt->next != NULL)
    {
        nxt->next->prev = nxt->prev;
    }
    if (nxt->prev != NULL)
    {
        nxt->prev->next = nxt->next;
    }
}

void remove_end()
{
    if (tail == head)
    {
        tail = NULL;
        head = NULL;
        return;
    }

    tail = tail->prev;
    tail->next = NULL;
}

void print_status()
{
    print_head();
    print_tail();
    print_list();
}

void print_head()
{
    if (head == NULL)
    {
        cout << "Head=Null, ";
    }
    else
        cout << "Head=" << head->val << ", ";
}

void print_tail()
{
    if (tail == NULL)
    {
        cout << "Tail=Null, ";
    }
    else
        cout << "Tail=" << tail->val << ", ";
    cout << endl;
}

void print_list()
{
    Node *temp = head;
    Node *temp2 = tail;
    if (head == NULL)
    {
        cout << "Head2Tail: Empty" << endl;
        cout << "Tail2Head: Empty" << endl;
    }
    else
    {
        cout << "Head2Tail: ";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;

        cout << "Tail2Head: ";
        while (temp2 != NULL)
        {
            cout << temp2->val << " ";
            temp2 = temp2->prev;
        }
        cout << endl;
    }
}

// for singly linked list
void remove_duplicate()
{
    Node *temp = head;
    while (temp != NULL)
    {
        while (temp->next != NULL)
        {
            if (temp->val != temp->next->val)
                break;
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

// for linked list struct
void add(LinkedList *l1, LinkedList *l2)
{
    l1->tail->next = l2->head;
    l1->tail = l2->tail;
}
```

### Stack

```cpp
struct Node
{
    int val;
    Node* next;
    Node* prev;
};

struct Stack
{
    Node* head = NULL;
    Node* tail = NULL;
    int max_size;
    int curr_size = 0;
};

Node *create_node(int val)
{
    Node *temp = new Node;
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void push(Stack *s, int val)
{
    if (isFull(s))
    {
        cout << "Overflow" << endl;
        return;
    }

    Node *temp = create_node(val);

    if (isEmpty(s))
    {
        s->curr_size++;
        s->head = temp;
        s->tail = temp;
        return;
    }

    s->curr_size++;

    s->head->prev = temp;
    temp->next = s->head;
    s->head = temp;

    return;
}

void pop(Stack *s)
{
    if (isEmpty(s))
    {
        cout << "Underflow" << endl;
        return;
    }

    s->curr_size--;
    s->head = s->head->next;
    if (s->head == NULL)
    {
        s->tail = NULL;
    }
    else
    {
        s->head->prev = NULL;
    }
}

bool isEmpty(Stack *s)
{
    if (s->curr_size == 0)
        return true;
    else
        return false;
}

bool isFull(Stack *s)
{
    if (s->curr_size == s->max_size)
        return true;
    else
        return false;
}

int size(Stack *s)
{
    return s->curr_size;
}

int top(Stack *s)
{
    return s->head->val;
}

void print_stack(Stack *s)
{
    if (isEmpty(s))
        return;
    Node *temp = s->tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }

    cout << endl;
}
```

### Queue

```cpp
struct Node
{
    int val;
    Node *next;
};

struct Queue
{
    Node *head = NULL;
    Node *tail = NULL;
    int max_size;
    int curr_size = 0;
};

Node *create_node(int val)
{
    Node *temp = new Node;
    temp->val = val;
    temp->next = NULL;

    return temp;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Overflow" << endl;
        return;
    }

    Node *temp = create_node(val);

    if (isEmpty(q))
    {
        q->curr_size++;
        q->head = temp;
        q->tail = temp;
        return;
    }

    q->curr_size++;

    q->tail->next = temp;
    q->tail = temp;

    return;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Underflow" << endl;
        return;
    }

    q->curr_size--;

    q->head = q->head->next;
}

bool isEmpty(Queue *q)
{
    if (q->curr_size == 0)
        return true;
    else
        return false;
}

bool isFull(Queue *q)
{
    if (q->curr_size == q->max_size)
        return true;
    else
        return false;
}

int size(Queue *q)
{
    return q->curr_size;
}

int front(Queue *q)
{
    return q->head->val;
}

void print_queue(Queue *q)
{
    if (isEmpty(q))
        return;
    Node *temp = q->head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}
```

---

## Lab 6 + 7

### BST

```cpp
struct Node
{
    int val;
    Node* parent = NULL;
    Node* left_child = NULL;
    Node* right_child = NULL;
    int level = 0;
    int height = 0;
    int size = 1;
};

Node* tree_root = NULL;
int diameter = 0;

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

    check_balance(newNode);
}

int get_height(Node* curr)
{
    if(curr == NULL) return -1;
    else return curr->height;
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
        diameter = max(diameter, get_height(temp->left_child) + get_height(temp->right_child) + 1);
        temp->size = get_size(temp->left_child) + get_size(temp->right_child) + 1;
        temp = temp->parent;
    }
}

void left_rotate(Node* z)
{
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

int lca(int a, int b)
{
    Node* anode = searching(a);
    Node* bnode = searching(b);
        

    if((anode == NULL) || (bnode == NULL)) 
        cout << "Inavalid" << endl;
    else
    {
     	while(anode->level > bnode->level) 
            anode = anode->parent;
        while (bnode->level > anode->level) 
            bnode = bnode->parent;
        while(anode->val != bnode->val)
        {
            anode = anode->parent;
            bnode = bnode->parent;
        }

        return anode->val;
    }
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
```



​	


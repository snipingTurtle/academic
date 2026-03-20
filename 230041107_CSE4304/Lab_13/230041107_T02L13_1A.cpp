#include<iostream>

using namespace std;

void init(int node, int begin, int end, int tree[], int arr[])
{
    if(begin == end)
    {
        tree[node] = arr[begin];
        return;
    }

    int left = 2 * node;
    int right = (2 * node) + 1;
    int mid = (begin + end) / 2;

    init(left, begin, mid, tree, arr);
    init(right, mid + 1, end, tree, arr);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j, int tree[])
{
    if((i > e) || (j < b))
    {
        return 0;
    }

    if((b >= i) && (e <= j))
    {
        return tree[node];
    }

    int left = 2 * node;
    int right = (2 * node) + 1;
    int mid = (b + e) / 2;

    int q1 = query(left, b, mid, i, j, tree);
    int q2 = query(right, mid + 1, e, i, j, tree);

    return q1 + q2;
}

void update(int node, int b, int e, int i, int newValue, int tree[])
{
    if((i > e) || (i < b))
    {
        return;
    }

    if((b == i) && (e == i))
    {
        tree[node] = newValue;
        return;
    }

    int left = 2 * node;
    int right = (2 * node) + 1;
    int mid = (b + e) / 2;

    update(left, b, mid, i, newValue, tree);
    update(right, mid + 1, e, i, newValue, tree);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n, q;
    cin >> n >> q;

    int arr[n + 1];
    int tree[2 * n];

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    init(1, 1, n, tree, arr);

    while(q--)
    {
        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int i;
            cin >> i;

            cout << arr[i] << " (";

            arr[i] = 0;
            for(int i = 1; i <= n; i++)
            {
                if(i != n) cout << arr[i] << " ";
                else cout << arr[i] << ")";
            }
            cout << endl;

            update(1, 1, n, i, 0, tree);
        }
        else if(choice == 2)
        {
            int i, v;
            cin >> i >> v;

            arr[i] += v;
            for(int i = 1; i <= n; i++)
            {
                if(i != n) cout << arr[i] << " ";
                else cout << arr[i] << ")";
            }
            cout << endl;

            update(1, 1, n, i, arr[i], tree);
        }
        else if(choice == 3)
        {
            int i, j;
            cin >> i >> j;

            cout << query(1, 1, n, i, j, tree) << endl;
        }
    }
}

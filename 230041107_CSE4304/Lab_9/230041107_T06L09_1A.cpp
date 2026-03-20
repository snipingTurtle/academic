#include<iostream>
#include<vector>

using namespace std;

struct node
{
    node *next[2];

    node()
    {
        for(int i = 0; i < 2; i++)
        {
            next[i] = NULL;
        }
    }
};

node* root;

void insert_node(int n)
{
    node *curr = root;

    for(int i = 31; i >= 0; i--)
    {
        int idx;
        if((1<<i) & n) idx = 1;
        else idx = 0;

        if(curr->next[idx] == NULL)
        {
            curr->next[idx] = new node();
        }

        curr = curr->next[idx];
    }
}

int xr(int n)
{
    int res = 0;

    node *curr = root;

    for(int i = 31; i >= 0; i--)
    {
        int idx;
        if((1<<i) & n) idx = 1;
        else idx = 0;

        if(curr->next[idx ^ 1] != NULL)
        {
            res += (1<<i);
            curr = curr->next[idx ^ 1];
        }
        else curr = curr->next[idx];
    }

    return res;
}

int main()
{
    root = new node();

    int n;

    vector<int> v;

    while(cin >> n)
    {
        insert_node(n);
        v.emplace_back(n);
    }

    int res = 0;

    for(int i = 0; i < (int)v.size(); i++)
    {
        res = max(res, xr(v[i]));
    }

    cout << res << endl;
}
#include<iostream>

using namespace std;

struct node
{
    bool endmark;
    node *next[26];
    int num;

    node()
    {
        endmark = false;
        num = 0;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

node* root;

void insert_node(string str)
{
    node *curr = root;

    int len = str.size();

    for(int i = 0; i < len; i++)
    {
        int idx = str[i] - 'a';

        if(curr->next[idx] == NULL)
        {
            curr->next[idx] = new node();
        }

        curr = curr->next[idx];
    }
    if(curr->endmark == false)
    {
        node *temp = root;
        for(int i = 0; i < len; i++)
        {
            int idx = str[i] - 'a';

            temp = temp->next[idx];
            temp->num = temp->num + 1;
        }
    }

    curr->endmark = true;
}

int search_node(string str)
{
    int len = str.size();

    node* curr = root;
    for(int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id] == NULL)
        {
            return 0;
        }

        curr = curr->next[id];
    }

    int res = curr->num;
    return res;
}

int main()
{
    root = new node();

    int n, q;
    cin >> n >> q;

    while(n--)
    {
        string s;
        cin >> s;

        int len = s.size();
        for(int i = 0; i < len; i++) s[i] = tolower(s[i]);

        insert_node(s);
    }

    while(q--)
    {
        string s;
        cin >> s;

        int len = s.size();
        for(int i = 0; i < len; i++) s[i] = tolower(s[i]);

        int res = search_node(s);

        cout << res << endl;
    }
}

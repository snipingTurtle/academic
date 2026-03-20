#include<iostream>

using namespace std;

struct node
{
    bool endmark;
    node *next[26];

    node()
    {
        endmark = false;
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
    curr->endmark = true;
}

bool search_node(string str)
{
    int len = str.size();

    node* curr = root;
    for(int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id] == NULL)
        {
            return false;
        }

        curr = curr->next[id];
    }

    return curr->endmark;
}

void display(node* curr, string s = "")
{
    if(curr->endmark == true) cout << s << endl;

    for(int i = 0; i < 26; i++)
    {
        if(curr->next[i] != NULL)
        {
            s.push_back('a' + i);
            display(curr->next[i], s);
            s.pop_back();
        }
    }
}

int main()
{
    root = new node();

    while(1)
    {
        string s;
        cin >> s;

        if(s == "-1") break;

        insert_node(s);
    }

    display(root);

    while(1)
    {
        string s;
        cin >> s;

        if(s == "-1") break;

        if(search_node(s)) cout << "T ";
        else cout << "F ";
    }
    cout << endl;
}

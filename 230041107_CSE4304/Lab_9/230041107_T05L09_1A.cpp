#include<iostream>
#include<sstream>

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

node* search_node(string str)
{
    int len = str.size();

    node* curr = root;
    for(int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id] == NULL)
        {
            return NULL;
        }

        curr = curr->next[id];
    }

    return curr;
}

int cnt;

void display(node* curr, string s = "")
{
    if(cnt == 3) return;
    if(curr->endmark == true) 
    {
        cout << s << " ";
        cnt++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(cnt == 3) break;
        if(curr->next[i] != NULL)
        {
            s.push_back('a' + i);
            display(curr->next[i], s);
            s.pop_back();
        }
    }
}

void pre_display(string s)
{
    int n = s.size();
    cnt = 0;

    node* curr = search_node(s);
    if(curr != NULL) display(curr, s);

    if(!cnt) cout << "Null\n";
}

int main()
{
    root = new node();
    string inp;
    getline(cin, inp);

    stringstream temp(inp);

    string product;

    while(getline(temp, product, ' '))
    {
        insert_node(product);
    }

    string s;
    cin >> s;

    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        pre_display(s.substr(0, i + 1));
        cout << endl;
    }
}
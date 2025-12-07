#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> sc;

    for(int i = 0; i < (int)s.size(); i++)
    {
        if(sc.empty() || (sc.top() != s[i])) sc.push(s[i]);
        else sc.pop();
    }

    stack<char> temp;
    while(!sc.empty()) 
    {
        temp.push(sc.top());
        sc.pop();
    }

    if(temp.empty()) cout << "NULL" << endl;
    else 
    {
        while(!temp.empty())
        {
            cout << temp.top();
            temp.pop();
        }
    }

    cout << endl;
}
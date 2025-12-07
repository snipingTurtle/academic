#include<deque>
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    stack<char> temp;
    deque<char> res;

    int sw = 0;

    for(int i = 0; i < n; i++)
    {
        if((s[i] == '[') || (s[i] == ']'))
        {
            while(!temp.empty())
            {
                res.push_front(temp.top());
                temp.pop();
            }

            if(s[i] == '[') sw = 1;
            else sw = 0;
        }
        else
        {
            if(sw)
            {
                temp.push(s[i]);
            }
            else
            {
                res.push_back(s[i]);
            }
        }
    }

    while(!temp.empty())
    {
        res.push_front(temp.top());
        temp.pop();
    }

    for(auto &x:res) cout << x;
    cout << endl;
}
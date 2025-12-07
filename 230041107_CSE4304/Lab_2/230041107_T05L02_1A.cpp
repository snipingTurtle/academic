#include<iostream> 
#include<stack>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        stack<char> sc;
        
        for(int i = 0; i < (int)s.size(); i++)
        {
            sc.push(s[i]);
        }

        while(!sc.empty())
        {
            cout << sc.top();
            sc.pop();
        }

        cout << endl;
    }
}
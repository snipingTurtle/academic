#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(') 
            st.push(s[i]);
        else
        {
            if(st.size())
            {
                st.pop();
                res += 2;
            }
        }
    }
    cout<<res<<"\n";
}



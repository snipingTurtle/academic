#include<iostream> 
#include<stack>

using namespace std;

int main()
{
    int i, j, k, l, t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        int res = 0;
        for(i = 0; i < n; i++)
        {
            if(s[i] == '(') 
                st.push(s[i]);
            else
            {
                if(st.size()) 
                    st.pop();
                else 
                    res++;
            }
        }
        cout << res << "\n";
    }
}
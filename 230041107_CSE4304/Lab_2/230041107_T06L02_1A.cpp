#include<iostream> 
#include<stack> 

using namespace std;

int main()
{
    int n;
    cin>>n;

    string buff;
    getline(cin, buff);

    for(int j = 0; j < n; j++)
    {
        string s;
        getline(cin, s);

        stack<char> st;
        int res = 1;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if((s[i] == '[') || (s[i] == '(') || (s[i] == '{')) st.push(s[i]);
            if(s[i] == ')')
            {
                if((st.empty()) ||(st.top() != '('))
                {
                    res = 0;
                    break;
                }
                else st.pop();
            }
            if(s[i] == '}')
            {
                if((st.empty()) ||(st.top() != '{'))
                {
                    res = 0;
                    break;
                }
                else st.pop();
            }
            if(s[i] == ']')
            {
                if((st.empty()) ||(st.top() != '['))
                {
                    res = 0;
                    break;
                }
                else st.pop();
            }
        }

        if(!st.empty()) res = 0;

        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
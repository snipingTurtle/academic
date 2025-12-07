#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        stack<double> st;

        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '+')
            {
                double a, b;
                if(!st.empty())
                {
                    a = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                if(!st.empty())
                {
                    b = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                st.push(a + b);
            }
            else if(s[i] == '-')
            {
                double a, b;
                if(!st.empty())
                {
                    a = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                if(!st.empty())
                {
                    b = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                st.push(b - a);
            }
            else if(s[i] == '/')
            {
                double a, b;
                if(!st.empty())
                {
                    a = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                if(!st.empty())
                {
                    b = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                st.push(b / a);
            }
            else if(s[i] == '*')
            {
                double a, b;
                if(!st.empty())
                {
                    a = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                if(!st.empty())
                {
                    b = st.top();
                    st.pop();
                } 
                else
                {
                    cout<<"Invalid\n";
                    break;
                }
                st.push(a * b);
            }
            else
            {
                st.push(s[i] - '0');
            }

            // if(!st.empty()) cout<<st.top()<<"\n";
        }

        double res = st.top();
        st.pop();
        if(!st.empty()) cout<<"Invalid\n";
        else cout<<res<<"\n";
    }
}
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int ar[n];
    for(int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }

    stack<int> st;

    int cnt = 1;

    for(int i = 0; i < n; i++)
    {
        if(cnt == ar[i])
        {
            cnt++;
            while(!(st.empty()))
            {
                if(st.top() == cnt)
                {
                    cnt++;
                    st.pop();
                }
                else break;
            }
        }
        else if(st.empty() || (ar[i] < st.top())) st.push(ar[i]);
        else 
        {
            cout<<"NO\n";
            return 0;
        }
    }
    if(st.empty()) cout<<"YES\n";
    else cout<<"NO\n";
}
#include<iostream> 
#include<stack>

using namespace std;

void print_stack(stack<int> st)
{
    stack<int> temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;

    int id;

    stack<int> st;
    while(1)
    {
        cin>>id;
        if(id == -1) break;
        else if(id == 1)
        {
            if(st.size() == n) 
            {
                cout<<"Overflow\n";
                continue;
            }
            int x;
            cin>>x;
            st.push(x);
            print_stack(st);
        }
        else if(id == 2)
        {
            if(st.empty())
            {
                cout<<"Underflow\n";
                continue;
            }
            st.pop();
            print_stack(st);
        }
        else if(id == 3)
        {
            if(st.empty()) cout<<"True\n";
            else cout<<"False\n";
        }
        else if(id == 4)
        {
            if(st.size() == n) cout<<"True\n";
            else cout<<"False\n";
        }
        else if(id == 5) cout<<st.size()<<"\n";
        else if(id == 6)
        {
            if(st.empty()) cout<<"Stack is Empty\n";
            else cout<<st.top()<<"\n";
        }
    }
}
#include<iostream> 
#include<stack>
#include<vector> 

using namespace std;

int main()
{
    vector<int> v;
    while(1)
    {
        int x;
        cin>>x;

        if(x == -1) break;
        v.emplace_back(x);
    }

    stack<int> st;
    int n = v.size();
    vector<int> res(n);
    res[n - 1] = -1;

    st.push(v[n - 1]);

    for(int i = n - 2; i >= 0; i--)
    {
        while(!st.empty() && (st.top() <= v[i])) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(v[i]);
    }

    for(auto &x:res) cout << x << " ";
    cout << endl; 
}
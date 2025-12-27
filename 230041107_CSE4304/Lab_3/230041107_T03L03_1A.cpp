#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    stack<int> man;
    stack<int> dum;

    while(q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x;
            cin >> x;

            if(man.size() == n)
            {
                cout << "Size:" << n << " Elements: Overflow!" << endl;
            }
            else
            {
                cout << "Size:" << (man.size() + 1) << " Elements: ";
                while(!man.empty())
                {
                    cout << man.top() << " ";
                    dum.push(man.top());
                    man.pop();
                }
                cout << x << endl;
                man.push(x);
                while(!dum.empty())
                {
                    man.push(dum.top());
                    dum.pop();
                }
            }
        }
        else
        {
            if(man.empty()) cout << "Size:0 Elements: Underflow" << endl;
            else
            {
                man.pop();
                if(man.size())
                {
                    cout << "Size:" << man.size() << " Elements: ";
                    while(!man.empty())
                    {
                        cout << man.top() << " ";
                        dum.push(man.top());
                        man.pop();
                    }
                    cout << endl;
                    while(!dum.empty())
                    {
                        man.push(dum.top());
                        dum.pop();
                    }
                }
                else cout << "Size:0 Elements: Null" << endl;
            }
        }
    }
}

#include<iostream>
#include<deque>

using namespace std;

int main()
{
    int n;
    cin >> n;

    deque<int> dq;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        dq.push_back(x);
    }

    string s;
    cin >> s;

    int pl = 0;
    if(s == "Ishraq") pl = 1;

    for(int i = 0; i < n - 1; i++)
    {
        if(pl) 
        {
            dq.push_back(dq.front());
            dq.pop_front();

            cout << "Ishraq "; 
        }
        else cout << "Daiyan ";

        dq.push_back(dq.front());
        dq.pop_front();
        
        dq.pop_front();

        for(auto &x:dq) cout << x << " ";
        cout << endl;

        pl ^= 1;
    }
}
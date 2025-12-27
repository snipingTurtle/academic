#include<iostream>
#include<deque>

using namespace std;

int main()
{
    string s, t;
    cin >> t >> s;

    deque<char> dq;
    for(int i = 0; i < (int)t.size(); i++) dq.push_back(t[i]);

    int res = 0;

    while(res < s.size())
    {
        for(int i = 0; i < (int)t.size(); i++)
        {
            t[i] = dq[i];
        }

        if(s == t) break;
        dq.push_front(dq.back());
        dq.pop_back();
        res++;
    }

    if(s == t)
    {
        if(res) cout << "Yes. After " << res << " clockwise rotations" << endl;
        else cout << "Yes. Rotation not needed." << endl;
    }
    else cout << "No" << endl;
}

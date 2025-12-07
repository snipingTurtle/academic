#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    map<int, int> id;

    for(int i = 0; i < t; i++)
    {
        int sz;
        cin >> sz;

        for(int j = 0; j < sz; j++)
        {
            int x;
            cin >> x;

            id[x] = i;
        }
    }

    queue<int> members[t];
    queue<int> teams;

    while(1)
    {
        string s;
        cin >> s;

        if(s == "STOP") break;
        else if(s == "ENQUEUE")
        {
            int x;
            cin >> x;

            if(members[id[x]].empty())
            {
                teams.push(id[x]);
            } 

            members[id[x]].push(x);
        }
        else
        {
            if(!teams.empty())
            {
                members[teams.front()].pop();
                if(members[teams.front()].empty()) teams.pop();
            }
        }
    }

    // for(auto &x:id) cout << x.first << " " << x.second << endl;

    // for(int i = 0; i < t; i++)
    // {
    //     cout << i << " ";
    //     while(!members[i].empty())
    //     {
    //         cout << members[i].front() << " ";
    //         members[i].pop();
    //     }
    //     cout << endl;
    // }

    while(!teams.empty())
    {
        while(!members[teams.front()].empty()) 
        {
            cout << members[teams.front()].front();
            members[teams.front()].pop();
            if(!members[teams.front()].empty() || (teams.size() != 1)) cout << ", ";
        }
        teams.pop();
    }

    cout << endl;
}
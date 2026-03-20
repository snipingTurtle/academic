#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        while(x--)
        {
            int k;
            cin >> k;
            edges[i].push_back(k);
        }
    }

    queue<int> q;

    vector<int> color(n, 0);

    for(int i = 0; i < n; i++)
    {
        if(!color[i])
        {
            color[i] = 1;
            q.push(i);

            while (!q.empty())
            {
                for(auto &x:edges[q.front()])
                {
                    if(color[x] == color[q.front()])
                    {
                        cout <<"NO" << endl;
                        return 0;
                    }
                    else if(!color[x])
                    {
                        color[x] = (-1) * color[q.front()];
                        q.push(x);
                    }
                }
                q.pop();
            }
        }
    }

    cout << "YES" << endl;
}
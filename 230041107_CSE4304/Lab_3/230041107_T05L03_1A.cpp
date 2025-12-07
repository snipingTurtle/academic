#include<iostream>
#include<queue>

using namespace std;


int main()
{
    string dum;
    int n;
    cin >> n;

    cin >> dum;

    int freq[2] = {0};

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        freq[x]++;
    }

    cin >> dum;

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        q.push(x);
    }

    while(!q.empty())
    {
        if(freq[q.front()])
        {
            freq[q.front()]--;
            q.pop();
        }
        else break;
    }

    cout << q.size() << endl;
}
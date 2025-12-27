#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int> pq;

    while(1)
    {
        int x;
        cin >> x;

        if(x == -1) break;
        pq.push(x);
    }

    while(pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();

        int y = pq.top();
        pq.pop();

        if(x != y)
        {
            pq.push(abs(y - x));
        }
    }

    if(pq.size())
    {
        cout  << pq.top() << endl;
        pq.pop();
    }
    else cout << "0" << endl;
}

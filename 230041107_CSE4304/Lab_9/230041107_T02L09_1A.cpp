#include<iostream>
#include<unordered_map>

using namespace std;

const int MAXN = 1e6;

int main()
{
    int arr[MAXN];

    int n = 0;

    unordered_map<int, int> um;

    while(1)
    {
        int x;
        cin >> x;

        if(x == -1) break;
        arr[n] = x;
        um[x]++;
        n++;
    }

    int sm;
    cin >> sm;

    int check = 1;

    for(int i = 0; i < n; i++)
    {
        if(um[sm - arr[i]] && (um[arr[i]]))
        {
            if(((arr[i] * 2) == sm) && (um[arr[i]] < 2)) continue;
            cout << "(" << arr[i] << "," << (sm - arr[i]) << ") ";
            um[sm - arr[i]]--;
            um[arr[i]]--;
            check = 0;
        }
    }

    if(check) cout << "No pairs found" << endl;
}

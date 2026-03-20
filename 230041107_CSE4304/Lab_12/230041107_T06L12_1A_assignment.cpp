#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;

int main()
{
    int n, m;
    cin >> n >> m;

    v.resize(n, vector<int>(m));

    for(auto &x:v)
    {
        for(auto &z:x) cin >> z;
    }

    
}
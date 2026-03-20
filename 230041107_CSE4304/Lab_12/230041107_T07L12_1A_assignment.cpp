#include<iostream>
#include<vector>

using namespace std;

bool check(const int &i, const int &j, const int &n, const int &m)
{
    if((i < 0) || (j < 0)) return false;
    if((i >= n) || (j >= m)) return false;
    return true;
}

void dfs(const int &i, const int &j, const int &n, const int &m, const vector<string> &grid, vector<vector<int>> &vis)
{
    if(!check(i, j, n, m)) return;
    if(grid[i][j] == '0') return;
    if(vis[i][j]) return;

    vis[i][j] = 1;

    dfs(i - 1, j, n, m, grid, vis);
    dfs(i + 1, j, n, m, grid, vis);
    dfs(i, j - 1, n, m, grid, vis);
    dfs(i, j + 1, n, m, grid, vis);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(auto &x:grid) cin >> x;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if((grid[i][j] == '1') && !vis[i][j])
            {
                res++;
                dfs(i, j, n, m, grid, vis);
            }
        }
    }

    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], vector<int> &vis, int src, int dst)
{
    vis[src] = 1;
    if (src == dst)
    {
        return true;
    }
    for (auto it : adj[src])
    {
        if (vis[it] == 0)
        {
            if (dfs(adj, vis, it, dst) == true)
            {
                return true;
            }
        }
    }
}
bool sol(vector<vector<int>> mat, int V, int src, int dst)
{
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mat[i][j] == 1 && i!=j)
            {
                adj[i].push_back(j);
            }
        }
    }
    
    vector<int> vis(V, 0);
    if (dfs(adj, vis, src, dst) == true)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            mat[i][j] = temp;
        }
    }
    int src, dst;
    cin >> src >> dst;
    if (sol(mat, n, src-1, dst-1) == true)
    {
        cout<< "Yes Path Exist";
    }
    else
    {
        cout<< "No Such Path Exist";
    }
    return 0;
}
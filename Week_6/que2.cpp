#include <bits/stdc++.h>
using namespace std;
bool bfs(int node, vector<int> adj[], int col, vector<int> &color)
{
    color[node] = col;
    queue<int> q;
    q.push(node);
    while (q.empty() == false)
    {
        int n = q.front();
        q.pop();
        for (auto itr : adj[n])
        {
            if (color[itr] == -1)
            {
                q.push(itr);
                color[itr] = !color[n];
            }
            else if (color[itr] == color[n])
            {
                return false;
            }
        }
    }
    return true;
}
bool sol(vector<vector<int>> mat, int V)
{
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mat[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> color(V, -1);
    return bfs(0, adj, 0, color);
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
    if (sol(mat, n) == true)
    {
        cout << "Yes Bipartite";
    }
    else
    {
        cout << "Not Bipartite";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool cycleCheck(int st,vector<int> adj[], vector<int> &vis,vector<int> &pathVis)
{
    vis[st] = 1;
    pathVis[st] = 1;
    for (auto it : adj[st])
    {
        if (vis[it] == 0)
        {
            if (cycleCheck(it,adj, vis, pathVis) == true)
            {
                return true;
            }
        }
        else if(pathVis[it] == 1){
            return true;
        }
    }
    pathVis[st] = 0;
    return false;
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
    vector<int> vis(V, 0);
    vector<int> pathVis(V,0);
    if (cycleCheck(0,adj, vis,pathVis) == true)
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
    if (sol(mat, n) == true)
    {
        cout << "Yes Cycle Exists";
    }
    else
    {
        cout << "No Cycle Exists";
    }
    return 0;
}
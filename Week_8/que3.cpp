#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 8;
    int m = 7;
    int v[n][m] = {{0, 0, 7, 5, 0, 0, 0},
                   {0, 0, 8, 0, 0, 0, 0},
                   {7, 8, 0, 9, 7, 0, 0},
                   {5, 0, 9, 0, 15, 6, 0},
                   {0, 5, 7, 15, 0, 8, 9},
                   {0, 0, 0, 6, 8, 0, 11},
                   {0, 0, 0, 0, 9, 11, 0}};
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0)
            {
                adj[i].push_back({j, v[i][j]});
                adj[j].push_back({i, v[i][j]});
            }
        }
    }
    vector<int> vis(n, 0);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    int sum = 0;
    while (pq.empty() == false)
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto itr : adj[node])
        {
            int adjNode = itr.first;
            int adjWt = itr.second;
            if (vis[adjNode] == 0)
            {
                pq.push({adjWt, adjNode});
            }
        }
    }
    cout << sum << endl;
    return 0;
}
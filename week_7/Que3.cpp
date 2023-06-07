#include <bits/stdc++.h>
using namespace std;

#define V 4

int shortestPathWithKEdges(const int graph[V][V], int src, int dest, int k) {
    int dp[V][V][k+1];
    
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dp[i][j][e] =   numeric_limits<int>::max();
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0) {
                dp[i][j][1] = graph[i][j];
            }
        }
    }
    
    for (int e = 2; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                for (int x = 0; x < V; x++) {
                    if (graph[i][x] != 0 && dp[x][j][e-1] !=   numeric_limits<int>::max()) {
                        dp[i][j][e] =   min(dp[i][j][e], dp[i][x][1] + dp[x][j][e-1]);
                    }
                }
            }
        }
    }
    
    return dp[src][dest][k];
}

int main() {
    int graph[V][V] = { {0, 10, 3, 0},
                        {0, 0, 0, 7},
                        {0, 0, 0, 6},
                        {0, 0, 0, 0} };
  
    int src = 0;
    int dest = 3;
    int k = 2;
  
    int shortestPath = shortestPathWithKEdges(graph, src, dest, k);
    if (shortestPath ==   numeric_limits<int>::max()) {
          cout << "There is no path with exactly " << k << " edges from vertex " << src << " to vertex " << dest <<   endl;
    } else {
          cout << "The weight of the shortest path with exactly " << k << " edges from vertex " << src << " to vertex " << dest << " is " << shortestPath <<   endl;
    }
  
    return 0;
}

/*Given a directed graph with two vertices ( source and destination). Design an algorithm and
implement it using a program to find the weight of the shortest path from source to destination
with exactly k edges on the path.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 4
int shortestPathWithKEdges(int graph[V][V], int src, int dest, int k) {
    int dp[V][V][k+1]; 
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dp[i][j][e] = INT_MAX;
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
                    if (graph[i][x] != 0 && dp[x][j][e-1] != INT_MAX) {
                        dp[i][j][e] = (dp[i][j][e] < dp[i][x][1] + dp[x][j][e-1]) ? dp[i][j][e] : (dp[i][x][1] + dp[x][j][e-1]);
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
    if (shortestPath == INT_MAX) {
        printf("There is no path with exactly %d edges from vertex %d to vertex %d\n", k, src, dest);
    } else {
        printf("The weight of the shortest path with exactly %d edges from vertex %d to vertex %d is %d\n", k, src, dest, shortestPath);
    }
  
    return 0;
}

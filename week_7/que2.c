#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 
void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
void bellmanFord(int graph[V][V], int src) {
    int dist[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative-weight cycle\n");
                return;
            }
        }
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = { {0, 6, 0, 0, 7, 0},
                        {0, 0, 5, -4, 8, -2},
                        {0, -2, 0, 0, 0, 0},
                        {2, 0, 7, 0, 0, 0},
                        {0, -3, 9, 2, 0, 0},
                        {0, 0, 0, 0, -5, 0} };
  
    bellmanFord(graph, 0); 
    return 0;
}

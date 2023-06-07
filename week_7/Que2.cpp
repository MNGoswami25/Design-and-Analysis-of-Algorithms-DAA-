#include <bits/stdc++.h>
using namespace std;

#define V 6

void printSolution(const  vector<int>& dist) {
     cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
         cout << i << " \t\t " << dist[i] << '\n';
}

void bellmanFord(const  vector< vector<int>>& graph, int src) {
     vector<int> dist(V,  numeric_limits<int>::max());
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] !=  numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] !=  numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                 cout << "Graph contains negative-weight cycle\n";
                return;
            }
        }
    }

    printSolution(dist);
}

int main() {
     vector< vector<int>> graph = {{0, 6, 0, 0, 7, 0},
                                           {0, 0, 5, -4, 8, -2},
                                           {0, -2, 0, 0, 0, 0},
                                           {2, 0, 7, 0, 0, 0},
                                           {0, -3, 9, 2, 0, 0},
                                           {0, 0, 0, 0, -5, 0}};

    bellmanFord(graph, 0);

    return 0;
}

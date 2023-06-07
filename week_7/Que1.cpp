#include <bits/stdc++.h>
using namespace std;

#define V 6

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet) {
    int min = std::numeric_limits<int>::max();
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(const std::vector<int>& dist) {
    std::cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t " << dist[i] << '\n';
}

void dijkstra(const std::vector<std::vector<int>>& graph, int src) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    std::vector<std::vector<int>> graph = {{0, 7, 9, 0, 0, 14},
                                           {7, 0, 10, 15, 0, 0},
                                           {9, 10, 0, 11, 0, 2},
                                           {0, 15, 11, 0, 6, 0},
                                           {0, 0, 0, 6, 0, 9},
                                           {14, 0, 2, 0, 9, 0}};

    dijkstra(graph, 0);

    return 0;
}

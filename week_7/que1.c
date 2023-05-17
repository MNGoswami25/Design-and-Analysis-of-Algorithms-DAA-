/*After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results. Can you also implement the same algorithm and verify the correctness of Akshay’s
results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)*/

//Dijkstra algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++){
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}
void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V]; 
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}

int main() {
        int graph[V][V] = { {0, 7, 9, 0, 0, 14},
                        {7, 0, 10, 15, 0, 0},
                        {9, 10, 0, 11, 0, 2},
                        {0, 15, 11, 0, 6, 0},
                        {0, 0, 0, 6, 0, 9},
                        {14, 0, 2, 0, 9, 0} };
  
    dijkstra(graph, 0); 
    return 0;
}

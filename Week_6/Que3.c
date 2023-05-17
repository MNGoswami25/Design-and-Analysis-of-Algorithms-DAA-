/*Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.*/
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];

bool isCyclicUtil(int vertex, int vertices) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        recStack[vertex] = true;
        for (int i = 0; i < vertices; i++) {
            if (graph[vertex][i]) {
                if (!visited[i] && isCyclicUtil(i, vertices)) {
                    return true;
                } else if (recStack[i]) {
                    return true;
                }
            }
        }
    }
    recStack[vertex] = false;
    return false;
}

bool isCyclic(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < vertices; i++) {
        if (isCyclicUtil(i, vertices)) {
            return true;
        }
    }
    return false;
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if (isCyclic(vertices)) {
        printf("Cycle exists in the graph");
    } else {
        printf("Cycle does not exist in the graph");
    }
    return 0;
}



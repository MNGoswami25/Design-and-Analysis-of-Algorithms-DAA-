/*1.Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)*/

#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int pathExists = 0;

void DFS(int current, int destination) {
    visited[current] = 1;
    if (current == destination) {
        pathExists = 1;
        return;
    }
    for (int i = 0; i < MAX; i++) {
        if (graph[current][i] && !visited[i]) {
            DFS(i, destination);
        }
    }
}

int main() {
    int vertices, source, destination;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <=vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source and destination vertex numbers: ");
    scanf("%d %d", &source, &destination);
    DFS(source, destination);
    if (pathExists) {
        printf("Yes Path Exists");
    } else {
        printf("No Such Path Exists");
    }
    return 0;
}

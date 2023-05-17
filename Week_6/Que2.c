/*Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)*/
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int graph[MAX][MAX];
int color[MAX];
bool isBipartite = true;

void BFS(int start, int vertices) {
    int queue[MAX], front = -1, rear = -1;
    queue[++rear] = start;
    color[start] = 1;
    while (front != rear) {
        int current = queue[++front];
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && color[i] == -1) {
                color[i] = 1 - color[current];
                queue[++rear] = i;
            } else if (graph[current][i] && color[i] == color[current]) {
                isBipartite = false;
                return;
            }
        }
    }
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
    for (int i = 0; i < vertices; i++) {
        color[i] = -1;
    }
    for (int i = 0; i < vertices; i++) {
        if (color[i] == -1) {
            BFS(i, vertices);
        }
    }
    if (isBipartite) {
        printf("Graph is Bipartite");
    } else {
        printf("Graph is not Bipartite");
    }
    return 0;
}

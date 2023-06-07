#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, cost;
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent;
    int *rank;
};

// Create a disjoint set with n elements
struct DisjointSet* createSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// Find the set representative of an element
int find(struct DisjointSet* set, int i) {
    if (set->parent[i] != i)
        set->parent[i] = find(set, set->parent[i]);
    return set->parent[i];
}

// Union of two sets based on rank
void unionSets(struct DisjointSet* set, int x, int y) {
    int xroot = find(set, x);
    int yroot = find(set, y);

    if (xroot == yroot)
        return;

    if (set->rank[xroot] < set->rank[yroot])
        set->parent[xroot] = yroot;
    else if (set->rank[xroot] > set->rank[yroot])
        set->parent[yroot] = xroot;
    else {
        set->parent[yroot] = xroot;
        set->rank[xroot]++;
    }
}

// Function to calculate the minimum cost to connect cities
int minimumCost(struct Edge* edges, int numEdges, int numCities) {
    struct DisjointSet* set = createSet(numCities);

    int minCost = 0;
    int edgeCount = 0;

    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int cost = edges[i].cost;

        if (find(set, src) != find(set, dest)) {
            unionSets(set, src, dest);
            minCost += cost;
            edgeCount++;

            if (edgeCount == numCities - 1)
                break;
        }
    }

    free(set->parent);
    free(set->rank);
    free(set);

    return minCost;
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    int numEdges = (numCities * (numCities - 1)) / 2;
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));

    int adjacencyMatrix[numCities][numCities];
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < numCities; i++) {
        for (int j = i + 1; j < numCities; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);

            if (adjacencyMatrix[i][j] != 0) {
                edges[(i * (2 * numCities - i - 3)) / 2 + j - i - 1].src = i;
                edges[(i * (2 * numCities - i - 3)) / 2 + j - i - 1].dest = j;
                edges[(i * (2 * numCities - i - 3)) / 2 + j - i - 1].cost = adjacencyMatrix[i][j];
            }
        }
    }

    int minimumBudget = minimumCost(edges, numEdges, numCities);
    printf("Minimum budget required: %d\n", minimumBudget);

    free(edges);

    return 0;
}

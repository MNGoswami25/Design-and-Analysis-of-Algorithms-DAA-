#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge2->weight - edge1->weight;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int maximum_budget(struct Edge edges[], int num_edges, int num_vertices) {
    struct Subset* subsets = (struct Subset*)malloc(num_vertices * sizeof(struct Subset));
    int max_spanning_weight = 0;

    for (int i = 0; i < num_vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, num_edges, sizeof(struct Edge), compare);

    for (int i = 0; i < num_edges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int src_parent = find(subsets, src);
        int dest_parent = find(subsets, dest);

        if (src_parent != dest_parent) {
            max_spanning_weight += edges[i].weight;
            unionSets(subsets, src_parent, dest_parent);
        }
    }

    free(subsets);

    return max_spanning_weight;
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    int num_edges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    struct Edge edges[num_edges];

    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < num_edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }

    int max_budget = maximum_budget(edges, num_edges, num_vertices);
    printf("Maximum budget required: %d\n", max_budget);

    return 0;
}

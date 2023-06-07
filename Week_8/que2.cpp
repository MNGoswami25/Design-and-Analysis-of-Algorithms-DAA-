#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct Subset {
    int parent;
    int rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
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

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int minimumCost(Graph graph) {
    int V = graph.V;
    vector<Edge> result;
    int e = 0;
    int i = 0;

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
    }

    int minCost = 0;
    for (i = 0; i < e; i++)
        minCost += result[i].weight;

    return minCost;
}

int main() {
    int n = 8;
    int m = 7;
    int v[n][m] = {{0, 0, 7, 5, 0, 0, 0},
                   {0, 0, 8, 0, 0, 0, 0},
                   {7, 8, 0, 9, 0, 0, 0},
                   {5, 0, 9, 0, 15, 6, 0},
                   {0, 0, 0, 15, 0, 8, 9},
                   {0, 0, 0, 6, 8, 0, 11},
                   {0, 0, 0, 0, 9, 11, 0}};

    Graph graph;
    graph.V = n;
    graph.E = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            if (v[i][j] != 0) {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edge.weight = v[i][j];
                graph.edges.push_back(edge);
                graph.E++;
            }
        }
    }

    int minCost = minimumCost(graph);
    cout << "Minimum Spanning Weight:"<<minCost << endl;

    return 0;
}

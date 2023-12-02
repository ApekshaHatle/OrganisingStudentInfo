#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 100;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to find the set of an element i
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Function to perform union of two subsets
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

// Comparison function to sort edges based on their weights
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(Edge edges[MAX_N], int V, int E) {
    // Allocate memory for subsets
    Subset subsets[MAX_N];

    // Initialize subsets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort the edges in ascending order of their weights
    sort(edges, edges + E, compare);

    // Initialize result
    Edge result[MAX_N];

    // Index used for the result array
    int i = 0;

    // Index used for the sorted edges array
    int e = 0;

    // Build the MST
    while (i < V - 1 && e < E) {
        Edge next_edge = edges[e++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[i++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the result
    cout << "Minimum Spanning Tree using Kruskal's Algorithm:" << endl;
    for (i = 0; i < V - 1; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(Edge edges[MAX_N], int V, int E) {
    int graph[MAX_N][MAX_N] = {0};

    // Fill the adjacency matrix
    for (int i = 0; i < E; i++) {
        graph[edges[i].src][edges[i].dest] = edges[i].weight;
        graph[edges[i].dest][edges[i].src] = edges[i].weight;
    }

    int parent[MAX_N];
    int key[MAX_N];
    bool mstSet[MAX_N];

    // Initialize keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    key[0] = 0;
    parent[0] = -1;

    // MST has V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u, min_key = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the result
    cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int choice;
    cout << "Choose the algorithm (1 for Kruskal, 2 for Prim): ";
    cin >> choice;

    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Edge edges[MAX_N];
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    switch (choice) {
        case 1:
            kruskalMST(edges, V, E);
            break;
        case 2:
            primMST(edges, V, E);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

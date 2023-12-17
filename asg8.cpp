#include <iostream>
#include <climits>

using namespace std;

const int MAX_N = 100;

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int V) {
    int min_dist = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v]==false && dist[v] <= min_dist) {
            min_dist = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

// Function that implements Dijkstra's single-source shortest path algorithm
void dijkstra(int graph[MAX_N][MAX_N], int src, int V) {
    int dist[MAX_N]; // The output array dist[i] holds the shortest distance from src to i

    bool sptSet[MAX_N]; // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in the sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is less than the current value of dist[v]
            if (sptSet[v]==false && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int V, E;

    // Input the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize the graph with all elements set to 0
    int graph[MAX_N][MAX_N] = {0};

    // Input the edges and weights
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
        graph[dest][src]=weight;
    }

    // Input the source vertex
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    
    // Find and print the shortest paths
    dijkstra(graph, src, V);

    return 0;
}
